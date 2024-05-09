#!/bin/bash

# Color codes
red='\033[0;31m'
green='\033[0;32m'
reset='\033[0m'  # Reset color

# Check for empty argument
if [[ $# -eq 0 ]]; then
  echo -e "${red}Error: Please provide a commit message.${reset}"
  exit 1
fi

# Validate commit message
validate_commit_message() {
  local message="$1"
  if [[ -z "$message" ]]; then
    echo -e "${red}Error: Please provide a commit message.${reset}"
    return 1
  fi
  message=$(echo "$message" | sed 's/[^[:graph:]]//g')
  echo "$message"
}

# Get commit message
message="$1"

# Validate message
message=$(validate_commit_message "$message")
if [[ $? -ne 0 ]]; then
  exit 1
fi

# Git operations with color feedback
git add . && echo -e "${green}Files added to staging area.${reset}"
git commit -m "$message" && echo -e "${green}Commit created with message: '$message'.${reset}"
git push origin && echo -e "${green}Changes pushed to remote repository.${reset}" || echo -e "${red}Error: Push failed.${reset}"

echo ""  # Add an empty line for better formatting
