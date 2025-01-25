#!/bin/bash

# Default temp files
TEMP_RESULT_FILE="subfinder_temp_results.txt"
PROCESSED_FILE="processed_subdomains.txt"
WAYBACKDOMAIN="waybackdomain.txt"
WAYBACKOUTPUT="waybackurls.txt"




touch $WAYBACKOUTPUT $WAYBACKDOMAIN

> waybackdomain.txt
> waybackurls.txt
# Variables for process control
SUBFINDER_PID=""
MONITOR_PID=""
INACTIVE_DOMAIN_CHECK=""
PAUSED=false

# Function to display help
show_help() {
    cat <<EOF
Usage: $0 -d <domain> -o <output_file>

Options:
  -d, --domain <domain>      Specify the target domain.
  -o, --output <file>        Specify the output file for processed results.
  -h, --help                 Display this help message and exit.

Examples:
  $0 -d example.com -o results.txt
EOF
    exit 0
}

# Cleanup temp files on exit
cleanup() {
    rm -f "$TEMP_RESULT_FILE" "$PROCESSED_FILE"
}
trap cleanup EXIT

monitor_subfinder() {
    while kill -0 "$SUBFINDER_PID" 2>/dev/null; do
        sleep 15 # Check every second
    done

    # Once the process completes, exit the script
    echo "Subfinder process completed. Exiting script."
    exit 0
}

check_active_urls() {
    # Check if a filename is provided
    if [ -z "$1" ]; then
        echo "Usage: check_active_urls <file_name>"
        return 1
    fi

    INPUT_FILE="$1"

    # Check if the file exists
    if [ ! -f "$INPUT_FILE" ]; then
        echo "Error: File '$INPUT_FILE' does not exist."
        return 1
    fi

    # Output file for active URLs
    OUTPUT_FILE="active_${INPUT_FILE}"

    # Clear the output file if it exists
    > "$OUTPUT_FILE"

    echo "Checking URLs from $INPUT_FILE..."

    # Loop through each URL in the input file
    while IFS= read -r url; do
        if curl --head --silent --fail "$url" >/dev/null; then
            echo "$url" >> "$OUTPUT_FILE"
            echo "Active: $url"
        else
            echo "Inactive: $url"
        fi
    done < "$INPUT_FILE"

    echo "Active URLs saved to $OUTPUT_FILE"
}

run_waybackurl(){

    local domain=$1
    (urlexplorer -t $domain && check_active_urls waybackurls.txt) &
    WAYBACK_PID=$
} 


# run_waybackurl(){

# local domain=$1
# (echo "$domain" | waybackurls -no-subs >> "$RESULT_FILE") &
# WAYBACK_PID=$!

# while true; do
#   # Read domains not yet processed
#   while IFS= read -r domain; do
#     if ! grep -qFx "$domain" "$PROCESSED_FILE"; then
#       echo "New domain found: $domain, launching waybackurls for it"
      
#       # Run waybackurls in the background and append results
#       (echo "$domain" | waybackurls -no-subs >> "$RESULT_FILE") &
      
#       # Mark domain as processed
#       echo "$domain" >> "$PROCESSED_FILE"

#       ## condition for fininshing waybackurls
#       if kill -0 $WAYBACK_PID 2>/dev/null; then
#         echo "waybackurls process (PID: $WAYBACK_PID) is running for $domain..."
#       else
#         echo "waybackurls process (PID: $WAYBACK_PID) has finished for $domain."
#       fi

#     fi
#   done < "$RESULT_FILE"

# }

# Function to run subfinder
run_subfinder() {
    local domain=$1
    echo "Running subfinder for domain: $domain..."
    find_subdomain -d "$domain" -o "$TEMP_RESULT_FILE" &
    SUBFINDER_PID=$!
    echo "Subfinder PID: $SUBFINDER_PID"
     # Start monitoring the process in the background
    monitor_subfinder &
}

# Function to process subdomains
process_subdomain() {
    local subdomain=$1
    local final_output_file=$2
    echo "Status checking for $subdomain..."
    status_domain -o "$final_output_file" "$subdomain" &
    #sleep 1
    #echo "$subdomain processed."
}

# Function to monitor and process new subdomains
monitor_subdomains() {
    OUTPUT_FILE=$1
    echo "Monitoring subdomains in $TEMP_RESULT_FILE..."
    touch "$PROCESSED_FILE" # Ensure processed file exists

    # Monitor for new subdomains
    tail -F "$TEMP_RESULT_FILE" | while read -r subdomain; do
        # Skip empty lines and already processed subdomains
        [[ -z "$subdomain" ]] && continue
        grep -qFx "$subdomain" "$PROCESSED_FILE" && continue

        # Process new subdomain
        process_subdomain "$subdomain" "$OUTPUT_FILE"

        # Mark as processed
        echo "$subdomain" >> "$PROCESSED_FILE"

        # # Append to output file
        # if [ -n "$OUTPUT_FILE" ]; then
        #     echo "$subdomain processed" >> "$OUTPUT_FILE"
        # fi
    done
}

# Control terminal for pausing, resuming, stopping, and exiting
control_terminal() {
    while true; do
        echo "Control Terminal: [pause | resume | stop | exit]"
        read -r command

        case $command in
            pause)
                if [ "$PAUSED" = false ]; then
                    echo "Pausing processes..."
                    kill -STOP "$SUBFINDER_PID" "$MONITOR_PID" 2>/dev/null
                    PAUSED=true
                else
                    echo "Already paused."
                fi
                ;;
            resume)
                if [ "$PAUSED" = true ]; then
                    echo "Resuming processes..."
                    kill -CONT "$SUBFINDER_PID" "$MONITOR_PID" 2>/dev/null
                    PAUSED=false
                else
                    echo "Already running."
                fi
                ;;
            stop)
                echo "Stopping subfinder and monitor..."
                kill "$SUBFINDER_PID" "$MONITOR_PID" 2>/dev/null
                break
                ;;
            exit)
                echo "Exiting script..."
                kill "$SUBFINDER_PID" "$MONITOR_PID" "$INACTIVE_DOMAIN_CHECK" 2>/dev/null
                exit 0
                ;;
            *)
                echo "Unknown command. Use [pause | resume | stop | exit]."
                ;;
        esac
    done
}


check_inactive_domains() {
    

    #OUTPUT_FILE="$1"
    INACTIVE_FILE="inactive_domains.txt"
    ACTIVE_FILE="active_waybackurls.txt"
    ACTIVE_DOMAINS_FILE="active_domain_from_waybackurls.txt"

    # Check if the inactive file exists
    if [ ! -f "$INACTIVE_FILE" ]; then
        echo "Error: File '$INACTIVE_FILE' does not exist."
        touch "$INACTIVE_FILE"
    fi

    # Create or clear the active domains file
    > "$ACTIVE_DOMAINS_FILE"
    
    # Function to continuously check for updates in the INACTIVE file
    while true; do
        # Read each domain from the INACTIVE file
        while IFS= read -r domain; do
            # Check if the domain exists in active_waybackurls.txt
            if grep -q "https://$domain" "$ACTIVE_FILE"; then
                # If found, append to active_domain_from_waybackurls.txt
                echo "$domain" >> "$ACTIVE_DOMAINS_FILE"
                echo "Active domain found: $domain"
            elif grep -q "http://$domain" "$ACTIVE_FILE"; then
                # If found, append to active_domain_from_waybackurls.txt
                echo "$domain" >> "$ACTIVE_DOMAINS_FILE"
                echo "Active domain found: $domain"
            fi
        done < "$INACTIVE_FILE"
        
        # Wait for new domains to be added to INACTIVE_$OUTPUT_FILE
        sleep 5
    done &
    
    echo "Background process to check inactive domains started."
}

# Main logic
main() {
    local domain=""
    OUTPUT_FILE=""

    # Parse arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            -d|--domain)
                domain="$2"
                shift 2
                ;;
            -o|--output)
                OUTPUT_FILE="$2"
                shift 2
                ;;
            -h|--help)
                show_help
                ;;
            *)
                echo "Unknown option: $1"
                show_help
                ;;
        esac
    done

    # Validate arguments
    if [ -z "$domain" ]; then
        echo "Error: Domain is required."
        show_help
    fi

    if [ -z "$OUTPUT_FILE" ]; then
        echo "Error: Output file is required."
        show_help
    fi

    # Run subfinder and monitor in parallel
    run_waybackurl "$domain" 
    run_subfinder "$domain"
    check_inactive_domains &
    INACTIVE_DOMAIN_CHECK=$!
    monitor_subdomains "$OUTPUT_FILE" &
    MONITOR_PID=$!

    # Launch control terminal
    control_terminal
}

main "$@"
