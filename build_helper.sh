#!/bin/bash

set -e

KANSEI_DIR="$(pwd)"
RESOURCE_DIR="$KANSEI_DIR/res"

# rebuild cmake files
cmake -S . -B build

# build using cmake
cmake --build build

# if specified, run binary in resource dir
if [[ "$1" == "run-after-build" ]]; then
    cd res
    ../bin/kansei
fi
