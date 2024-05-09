#!/bin/bash
red='\033[0;31m'
green='\033[1;32m'
reset='\033[0m'

if [[ $# -eq 0 ]]; then
  echo -e "${red}Error: Please provide a commit message.${reset}"
  exit 1
fi

validate_commit_message()
{
  local message="$1"
  if [[ -z "$message" ]]; then
    echo -e "${red}Error: Please provide a commit message.${reset}"
    return 1
  fi
  message=$(echo "$message" | sed 's/[^[:graph:]]//g')
  echo "$message"
}
message="$1"
message=$(validate_commit_message "$message")
if [[ $? -ne 0 ]]; then
  exit 1
fi

git add . && echo -e "${green}Files added to staging area.${reset}"
git commit -m "$message" && echo -e "${green}Commit created with message: '$message'.${reset}"
git push origin && echo -e "${green}Changes pushed to remote repository.${reset}" || echo -e "${red}Error: Push failed.${reset}"

echo ""
