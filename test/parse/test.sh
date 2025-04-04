#!/bin/bash

declare -A test_cases=(
    ["rt_file/error_A_brightness_big.rt"]=1
    ["rt_file/error_A_brightness_small.rt"]=1
    ["rt_file/error_A_color_big.rt"]=1
    ["rt_file/error_A_color_small.rt"]=1
    ["rt_file/error_A_duplicate.rt"]=1
    ["rt_file/error_A_char.rt"]=1
    ["rt_file/success.rt"]=0
)

for file in "${!test_cases[@]}"; do
    expected_status="${test_cases[$file]}"
    ./parse "$file" 2> /dev/null
    if [ "$?" -eq "$expected_status" ]; then
        echo -e "\e[32mOK\e[0m"
    else
        echo -e "\e[31mNG (got $status)\e[0m"
    fi
done

