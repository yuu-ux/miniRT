#!/bin/bash

declare -A test_cases=(
    # Ambient light tests
    ["rt_file/_A/arg_more.rt"]=1
    ["rt_file/_A/arg_less.rt"]=1
    ["rt_file/_A/brightness_big.rt"]=1
    ["rt_file/_A/brightness_small.rt"]=1
    ["rt_file/_A/color_big.rt"]=1
    ["rt_file/_A/color_small.rt"]=1
    ["rt_file/_A/duplicate.rt"]=1
    ["rt_file/_A/char.rt"]=1

    # Camera tests
    ["rt_file/_C/arg_more.rt"]=1
    ["rt_file/_C/arg_less.rt"]=1
    ["rt_file/_C/char.rt"]=1
    ["rt_file/_C/fov_big.rt"]=1
    ["rt_file/_C/fov_small.rt"]=1
    ["rt_file/_C/vec_big.rt"]=1
    ["rt_file/_C/vec_small.rt"]=1
    ["rt_file/_C/duplicate.rt"]=1

    # Light tests
    ["rt_file/_L/arg_more.rt"]=1
    ["rt_file/_L/arg_less.rt"]=1
    ["rt_file/_L/char.rt"]=1
    ["rt_file/_L/color_big.rt"]=1
    ["rt_file/_L/color_small.rt"]=1
    ["rt_file/_L/light_big.rt"]=1
    ["rt_file/_L/light_small.rt"]=1
    ["rt_file/_L/duplicate.rt"]=1

    # Sphere tests
    ["rt_file/_sp/arg_less.rt"]=1
    ["rt_file/_sp/arg_more.rt"]=1
    ["rt_file/_sp/char.rt"]=1
    ["rt_file/_sp/color_big.rt"]=1
    ["rt_file/_sp/color_small.rt"]=1
	["rt_file/_sp/invalid_num.rt"]=1

    # Plane tests
    ["rt_file/_pl/arg_less.rt"]=1
    ["rt_file/_pl/arg_more.rt"]=1
    ["rt_file/_pl/char.rt"]=1
    ["rt_file/_pl/color_big.rt"]=1
    ["rt_file/_pl/color_small.rt"]=1
    ["rt_file/_pl/vec.rt"]=1
    ["rt_file/_pl/vec_big.rt"]=1
    ["rt_file/_pl/vec_small.rt"]=1

    # Cylinder tests
    ["rt_file/_cy/arg_less.rt"]=1
    ["rt_file/_cy/arg_more.rt"]=1
    ["rt_file/_cy/char.rt"]=1
    ["rt_file/_cy/color_big.rt"]=1
    ["rt_file/_cy/color_small.rt"]=1
    ["rt_file/_cy/vec.rt"]=1
    ["rt_file/_cy/vec_big.rt"]=1
    ["rt_file/_cy/vec_small.rt"]=1

    # Success case
    ["rt_file/success.rt"]=0
)

make
for file in "${!test_cases[@]}"; do
    expected_status="${test_cases[$file]}"
    ./parse "$file" 2> /dev/null
    if [ "$?" -eq "$expected_status" ]; then
        echo -e "$file: \e[32mOK\e[0m"
    else
        echo -e "$file: \e[31mNG\e[0m"
    fi
done

