#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage: $0 <directory_name>"
  exit 1
fi

DIR_NAME=$1

BASE_DIR="srcs"

mkdir -p $BASE_DIR

mkdir -p $BASE_DIR/$DIR_NAME
touch $BASE_DIR/$DIR_NAME/$DIR_NAME.c

echo "Directory and file created successfully in $BASE_DIR/$DIR_NAME"
