#!/bin/bash

set -e  # Exit on any command failure
set -o pipefail

# Define filenames
SCRIPTS=("find_subdomain.sh" "urlexplorer.sh" "check_domain.sh" "parallel_subdomain_status.sh")
BINARIES=("find_subdomain" "urlexplorer" "domain_status" "bug_hunter")

# Cleanup any previous builds
echo "[*] Cleaning previous builds..."
rm -rf bug_package bug_hunter.run *.x.c *.sh.x "${BINARIES[@]}" 2>/dev/null || true

# Check for required tools
command -v shc >/dev/null 2>&1 || { echo >&2 "[!] shc is not installed. Install it and rerun."; exit 1; }
command -v makeself >/dev/null 2>&1 || { echo >&2 "[!] makeself is not installed. Install it and rerun."; exit 1; }

# Compile scripts using shc
echo "[*] Compiling scripts with shc..."
shc -f find_subdomain.sh -o find_subdomain || { echo "[!] Failed to compile find_subdomain.sh"; exit 1; }
shc -f urlexplorer.sh -o urlexplorer || { echo "[!] Failed to compile urlexplorer.sh"; exit 1; }
shc -f check_domain.sh -o domain_status || { echo "[!] Failed to compile check_domain.sh"; exit 1; }
shc -f parallel_subdomain_status.sh -o bug_hunter || { echo "[!] Failed to compile parallel_subdomain_status.sh"; exit 1; }

# Remove temporary shc files (*.sh.x and *.x.c)
echo "[*] Cleaning up temporary files (*.sh.x and *.x.c)..."
rm -f *.sh.x *.x.c

# Prepare packaging directory
echo "[*] Creating package directory..."
mkdir -p bug_package
mv find_subdomain urlexplorer domain_status bug_hunter bug_package/

# Create launcher script
echo "[*] Creating start.sh launcher..."
cat << 'EOF' > bug_package/start.sh
#!/bin/bash
chmod +x find_subdomain urlexplorer domain_status bug_hunter
export PATH="$(pwd):$PATH"
./bug_hunter "$@"
EOF
chmod +x bug_package/start.sh

# Package everything with makeself
echo "[*] Creating self-extracting package..."
makeself bug_package bug_hunter.run "Bug Hunter All-In-One" ./start.sh

# Clean up intermediate files
echo "[*] Cleaning up intermediate files..."
rm -rf bug_package

# Final output message
echo "[+] Build complete: ./bug_hunter.run"

