#!/bin/bash

validate_commit_message()
{
  local message="$1"
  if [[ -z "$message" ]]; then
    echo "Error: Please provide a commit message."
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

git add .
git commit -m "$message"
git push origin

echo "Commit added, pushed with message: '$message'"
