#!/bin/bash

# Check if a filename is passed as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <source-file.cpp>"
  exit 1
fi

# Get the filename fom the first argument
FILE=$1

# Compile the C++ file with g++ using the specified options
g++ -std=c++11 -O2 -Wall "$FILE" -o "${FILE%.cpp}"

# Check if compilation was successful
if [ $? -eq 0 ]; then
  echo -e "\033[0;32mCompilation successful! Executable created: ${FILE%.cpp}\033[0m"
else
  echo "Compilation failed."
fi
