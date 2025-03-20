#!/bin/bash
cd "$(dirname "$0")/YYKit"
mkdir -p include
rm -rf include/*
find . -path "./include" -prune -o -name "*.h" -print0 | while IFS= read -r -d "" file; do filename=$(basename "$file"); cp "$file" "include/$filename"; done
echo "头文件已同步到 include 目录"
