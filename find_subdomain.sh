#!/bin/bash

# Parse arguments for domain (-d) and output file (-o)
while getopts "d:o:" opt; do
  case ${opt} in
    d) DOMAIN=$OPTARG ;;
    o) OUTPUT_FILE=$OPTARG ;;
    *) echo "Usage: $0 -d DOMAIN -o OUTPUT_FILE"; exit 1 ;;
  esac
done

if [ -z "$DOMAIN" ] || [ -z "$OUTPUT_FILE" ]; then
  echo "Both -d (domain) and -o (output file) are required."
  exit 1
fi

# Temporary files for tool outputs
SUBFINDER_TEMP="subfinder_temp.txt"
AMASS_TEMP="amass_temp.txt"
SUBLIST3R_TEMP="sublist3r_temp.txt"
FILTERED_AMASS="filtered_amass_temp.txt"

# Start tools in the background and save their PIDs
subfinder -d "$DOMAIN" -silent -o "$SUBFINDER_TEMP" &
SUBFINDER_PID=$!

amass enum -d "$DOMAIN" -o "$AMASS_TEMP" &
AMASS_PID=$!

sublist3r -d "$DOMAIN" -o "$SUBLIST3R_TEMP" &
SUBLIST3R_PID=$!

# Start the Merger process
(
  while :; do
    # Ensure amass_temp.txt exists and is not empty before filtering
    if [[ -s "$AMASS_TEMP" ]]; then
      grep -oP '(?<=-->\s)[a-zA-Z0-9.-]+(?=\s\(FQDN\))' "$AMASS_TEMP" > "$FILTERED_AMASS"
    else
      echo "Waiting for Amass output to be generated..."
      #sleep 1
      #continue
    fi

    # Merge data from temp files
    cat "$SUBFINDER_TEMP" "$FILTERED_AMASS" "$SUBLIST3R_TEMP" 2>/dev/null | sort -u > "$OUTPUT_FILE"

    # Check if all tools have completed
    if ! ps -p $SUBFINDER_PID > /dev/null 2>&1 &&
       ! ps -p $AMASS_PID > /dev/null 2>&1 &&
       ! ps -p $SUBLIST3R_PID > /dev/null 2>&1; then
      break
    fi

    sleep 2
  done
) &
MERGER_PID=$!

# Monitor tool status
monitor_status() {
  echo "======================== CONTROL TERMINAL ========================"
  echo "=== Tool Status ==="
  echo "Subfinder: $(check_status $SUBFINDER_PID)"
  echo "Amass:     $(check_status $AMASS_PID)"
  echo "Sublist3r: $(check_status $SUBLIST3R_PID)"
  echo "Merger:    $(check_status $MERGER_PID)"
  echo "================================================================="
}

check_status() {
  if ps -p $1 > /dev/null 2>&1; then
    echo "Running"
  else
    echo "Completed"
  fi
}

control_terminal() {
  while true; do
  if [[ -f .exit_control_terminal ]]; then
    echo "Merger completed. Exiting control terminal."
    rm -f .exit_control_terminal
    break
  fi

  read -p "Enter command (status/pause/resume/stop/exit): " cmd
  case $cmd in
    status) 
      echo "=== Tool Status ==="
      monitor_status
      ;;
    pause)
      echo "Pausing all tools..."
      kill -STOP $SUBFINDER_PID $AMASS_PID $SUBLIST3R_PID $MERGER_PID
      ;;
    resume)
      echo "Resuming all tools..."
      kill -CONT $SUBFINDER_PID $AMASS_PID $SUBLIST3R_PID $MERGER_PID
      ;;
    stop)
      echo "Stopping all tools..."
      kill $SUBFINDER_PID $AMASS_PID $SUBLIST3R_PID $MERGER_PID
      break
      ;;
    exit)
      echo "Exiting control terminal..."
      break
      ;;
    *)
      echo "Invalid command."
      ;;
  esac
done

}

pause_tool() {
  case $1 in
    subfinder) kill -STOP $SUBFINDER_PID ;;
    amass) kill -STOP $AMASS_PID ;;
    sublist3r) kill -STOP $SUBLIST3R_PID ;;
    *) echo "Invalid tool name." ;;
  esac
}

resume_tool() {
  case $1 in
    subfinder) kill -CONT $SUBFINDER_PID ;;
    amass) kill -CONT $AMASS_PID ;;
    sublist3r) kill -CONT $SUBLIST3R_PID ;;
    *) echo "Invalid tool name." ;;
  esac
}

stop_tool() {
  case $1 in
    subfinder) kill $SUBFINDER_PID ;;
    amass) kill $AMASS_PID ;;
    sublist3r) kill $SUBLIST3R_PID ;;
    *) echo "Invalid tool name." ;;
  esac
}

# Background process to monitor Merger completion
(
  while ps -p $MERGER_PID > /dev/null 2>&1; do
    sleep 1
  done

  echo "Merger completed. Cleaning up..."
  kill $SUBFINDER_PID $AMASS_PID $SUBLIST3R_PID 2>/dev/null
  rm -f "$SUBFINDER_TEMP" "$AMASS_TEMP" "$SUBLIST3R_TEMP" "$FILTERED_AMASS"

  # Notify control terminal to exit
  touch .exit_control_terminal
  exit 0
) &


# Start the control terminal
#control_terminal
