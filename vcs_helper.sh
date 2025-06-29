#!/bin/bash

set -e

KANSEI_DIR="$(pwd)"
LUX_DIR="$KANSEI_DIR/external/lux"

# commit/push lux if needed
cd "$LUX_DIR"

echo "commiting and pushing lux changes"
if [[ -n $(git status --porcelain) ]]; then
    read -p "Enter commit message for lux: " LUX_COMMIT_MSG
    LUX_COMMIT_MSG=${LUX_COMMIT_MSG:-"Updated"}

    git add .
    git commit -m "$LUX_COMMIT_MSG"
    git push
else
    echo "no changes made to lux, skipping"
fi

# commit/push kansei if needed
cd "$KANSEI_DIR"
git add external/lux

echo "commiting and pushing kansei changes"
if [[ -n $(git status --porcelain) ]]; then
    read -p "Enter commit message for kansei: " KANSEI_COMMIT_MSG
    LATEST_LUX_HASH=$(git -C external/lux rev-parse --short HEAD)
    KANSEI_COMMIT_MSG=${KANSEI_COMMIT_MSG:-"Updated"}
    KANSEI_COMMIT_MSG="$KANSEI_COMMIT_MSG (lux@$LATEST_LUX_HASH)"

    git add .
    git commit -m "$KANSEI_COMMIT_MSG"
    git push
else
    echo "no changes make to kansei, skipping"
fi
