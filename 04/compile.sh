#!/usr/bin/env bash
# Portable runner: compiles and runs a single C++ file.
# Usage:
#   ./run.sh <name> [args...]
#   # where <name> corresponds to <name>.cpp in ./ or ./src/

set -euo pipefail

CXX=${CXX:-g++}
CXXFLAGS=${CXXFLAGS:-"-std=c++17 -O2 -Wall -Wextra -pedantic"}
LDFLAGS=${LDFLAGS:-""}
BIN_DIR=${BIN_DIR:-bin}

if [[ $# -lt 1 ]]; then
  echo "Usage: $0 <name> [args...]"
  exit 1
fi

name="$1"
shift || true

src=""
if [[ -f "$name" ]]; then
  src="$name"
else
  echo "Error: could not find $name.cc in ."
  exit 1
fi

mkdir -p "$BIN_DIR"
out="$BIN_DIR/$name"

# Rebuild only if needed
if [[ ! -x "$out" || "$src" -nt "$out" ]]; then
  echo "Compiling $src -> $out"
  eval "$CXX $CXXFLAGS \"$src\" -o \"$out\" $LDFLAGS"
fi

echo "Running $out $*"
"$out" "$@"
