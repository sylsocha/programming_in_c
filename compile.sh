#!/bin/bash

# Find all C files recursively in subdirectories
find . -name '*.c' | while read file; do
    if [ -f "$file" ]; then
        filename=$(basename "$file" .c)
        output_path=$(dirname "$file")
        # Check if math.h exists
        if grep -q '#include *<math\.h>' "$file"; then
            # Check the operating system
            if [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
                clang -o "${output_path}/${filename}.exe" "$file" -lm -L/path/to/directory/containing/math/library
            else
                clang -o "${output_path}/${filename}" "$file" -lm
                clang -o "${output_path}/${filename}.exe" "$file" -lm
            fi
        else
            clang -o "${output_path}/${filename}" "$file"
            clang -o "${output_path}/${filename}.exe" "$file"
        fi
        if [ $? -eq 0 ]; then
            echo "Compilation successful for $file"
        else
            echo "Error compiling $file"
            exit 1 # Exit the pipeline with a non-zero status code
        fi
    fi
done
