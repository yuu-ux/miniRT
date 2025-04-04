#!/bin/bash

declare -A test_cases=(
    ["rt_file/error_brightness_big.rt"]=1
    ["rt_file/error_brightness_small.rt"]=1
    ["rt_file/error_color_big.rt"]=1
    ["rt_file/error_color_small.rt"]=1
    ["rt_file/error_duplicate.rt"]=1
    ["rt_file/success.rt"]=0
)

for file in "${!test_cases[@]}"; do
    expected_status="${test_cases[$file]}"
    ./parse "$file"
    if [ "$?" -eq "$expected_status" ]; then
        echo -e "\e[32mOK\e[0m"
    else
        echo -e "\e[31mNG (got $status)\e[0m"
    fi
done

