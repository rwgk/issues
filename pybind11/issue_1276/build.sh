#! /usr/bin/bash
set -x
clang++ -o main_comment_2018-02-16.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -Werror -I/usr/local/google/home/rwgk/forked/pybind11/include -I/usr/include/python3.10 main_comment_2018-02-16.cpp
clang++ -o main_comment_2018-02-16 -rdynamic -O0 -g main_comment_2018-02-16.o -lpython3.10 -lpthread -ldl -lutil
