#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
BOLD_GREEN='\033[1;32m'
PINK='\033[0;95m'
NORMAL='\033[0m'

if [ $# -eq 0 ]; then
  echo -e "${GREEN}Please provide a C source file path and name as an argument.${NORMAL}"
  echo -e "\t ${PINK}Usage -> ./compiler.sh [path/to/file.c] ${NORMAL}"
  exit 1
fi

full_path="$1"

if [ ! -f "$full_path" ]; then
  echo -e "${RED}Error:${NORMAL} File '$full_path' does not exist."
  exit 1
fi

filename="${full_path%.*}"
gcc -o "$filename" "$full_path"

if [ $? -ne 0 ]; then
  echo -e "${RED}Error:${NORMAL} Compilation failed for '$full_path'."
  exit 1
fi

echo
echo -e "${BOLD_GREEN}** Compilation successful. **"
echo "Executable created as '$filename'."
