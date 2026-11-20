#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")/.."

echo "=== Equallibrim check ==="
echo "1. Compiling equallibrim.cpp..."
g++ -std=c++17 -Wall -Wextra -o /tmp/equallibrim equallibrim.cpp
echo "   Compile OK"

echo "2. Running equilibrium engine..."
timeout 30 /tmp/equallibrim > /tmp/equallibrim_output.txt
echo "   Run exit 0"

echo "3. Checking output..."
grep -q "EQUILIBRIUM ENGINE" /tmp/equallibrim_output.txt
grep -q "ENERGY STORAGE: 500.0000" /tmp/equallibrim_output.txt
grep -q "Physical Layer" /tmp/equallibrim_output.txt
grep -q "Stability: 0.5263" /tmp/equallibrim_output.txt
grep -q "State: TRANSITIONING" /tmp/equallibrim_output.txt
grep -q "State: UNSTABLE" /tmp/equallibrim_output.txt
grep -q "EQUILIBRIUM ENGINE COMPLETE" /tmp/equallibrim_output.txt
echo "   Output checks OK"

echo "All Equallibrim checks passed."
