#! /usr/bin/bash
set -x

clang++ -o main_issue_descr_complx.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -I$HOME/forked/pybind11/include -I/usr/include/python3.10 main_issue_descr.cpp
clang++ -o main_issue_descr_complx -rdynamic -O0 -g main_issue_descr_complx.o -lpython3.10 -lpthread -ldl -lutil

clang++ -o main_issue_descr_simple.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -I$HOME/forked/pybind11/include -I/usr/include/python3.10 -DPYBIND11_SIMPLE_GIL_MANAGEMENT main_issue_descr.cpp
clang++ -o main_issue_descr_simple -rdynamic -O0 -g main_issue_descr_simple.o -lpython3.10 -lpthread -ldl -lutil
