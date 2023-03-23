#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *-main.c *.c -o *-test && ./ *-test
