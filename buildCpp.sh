#!/bin/bash

# Check if an input file is provided
if [ -z "$1" ]; then
    echo "Usage: $0 <input_file.cpp>"
    exit 1
fi

INPUT_FILE="$1"
EXECUTABLE_NAME="${INPUT_FILE%.cpp}" # Removes .cpp extension to get executable name

# Compile the C++ program
echo "Compiling $INPUT_FILE..."
g++ "$INPUT_FILE" -o "$EXECUTABLE_NAME"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $EXECUTABLE_NAME..."
    # Run the compiled program
    ./"$EXECUTABLE_NAME"

    # Delete executable after running
    if [ -f "$EXECUTABLE_NAME" ]; then
        echo "Cleaning up: removing executable $EXECUTABLE_NAME"
        rm "$EXECUTABLE_NAME"
    fi
    
else
    echo "Compilation failed."
fi
