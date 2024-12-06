#!/bin/bash

# Default ports
DEFAULT_PORTS=(80 443 8080 8443 8090)

# Function to display help
show_help() {
    cat <<EOF
Usage: $0 [OPTIONS] <filename>

Options:
  -o, --output <file>      Specify the output file to store results. If not provided, results are only displayed on the terminal.
  -p, --ports <ports>      Specify a comma-separated list of ports to scan (e.g., 22,8080,8443). Default: 80,443,8080,8443,8090.
  -h, --help               Display this help message and exit.

Arguments:
  <filename>               File containing a list of domains (one per line).

Examples:
  $0 -o results.txt domains.txt
  $0 --ports 22,25,80 domains.txt
  $0 -o output.txt --ports 80,443 domains.txt
EOF
    exit 0
}

# Parse arguments
OUTPUT_FILE=""
PORTS=("${DEFAULT_PORTS[@]}")

while [[ $# -gt 0 ]]; do
    case $1 in
        -o|--output)
            OUTPUT_FILE="$2"
            shift 2
            ;;
        -p|--ports)
            IFS=',' read -r -a PORTS <<< "$2"
            shift 2
            ;;
        -h|--help)
            show_help
            ;;
        *)
            INPUT_FILE="$1"
            shift
            ;;
    esac
done

# Ensure input file is provided
if [ -z "$INPUT_FILE" ]; then
    echo "Error: Input file is required."
    echo "Use --help for usage information."
    exit 1
fi

# Check if the input file exists
if [ ! -f "$INPUT_FILE" ]; then
    echo "Error: File $INPUT_FILE not found!"
    exit 1
fi

# Initialize output (if specified)
if [ -n "$OUTPUT_FILE" ]; then
    header_format="%-25s %-10s %-10s %-10s %-15s %-15s\n"
    {
        printf "$header_format" "Domain" "Status" "HTTP Code" "HTTPS Code" "Ping Status" "Open Ports"
        printf "$header_format" "------" "------" "---------" "---------" "-----------" "----------"
    } > "$OUTPUT_FILE"
fi

# Function to check ports
check_ports() {
    local domain=$1
    local open_ports=()
    for port in "${PORTS[@]}"; do
        if timeout 3 bash -c "echo > /dev/tcp/$domain/$port" 2>/dev/null; then
            open_ports+=("$port")
        fi
    done
    echo "${open_ports[*]}"
}

# Process each domain
while IFS= read -r domain; do
    # Skip empty lines
    [[ -z "$domain" ]] && continue

    echo "Processing domain: $domain..."

    http_code=""
    https_code=""
    ping_status="Inactive"
    open_ports="None"

    # Check HTTP and HTTPS status
    http_code=$(curl -o /dev/null -s -w "%{http_code}" "http://$domain" || echo "N/A")
    https_code=$(curl -o /dev/null -s -w "%{http_code}" "https://$domain" || echo "N/A")

    # Check if ping is successful
    if ping -c 1 -W 2 "$domain" &>/dev/null; then
        ping_status="Active"
    fi

    # If ping works, check open ports
    if [ "$ping_status" == "Active" ]; then
        open_ports=$(check_ports "$domain")
        [ -z "$open_ports" ] && open_ports="None"
    fi

    # Format row data
    row_format="%-25s %-10s %-10s %-10s %-15s %-15s\n"
    row_data=$(printf "$row_format" "$domain" "$ping_status" "$http_code" "$https_code" "$ping_status" "$open_ports")

    # Print row to terminal
    echo "$row_data"

    # Append row to output file if specified
    if [ -n "$OUTPUT_FILE" ]; then
        echo "$row_data" >> "$OUTPUT_FILE"
    fi
done < "$INPUT_FILE"

if [ -n "$OUTPUT_FILE" ]; then
    echo "Domain status results saved to $OUTPUT_FILE"
fi

