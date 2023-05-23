#! /usr/bin/bash
if [ "$1" == "last_good" ]; then
  PYINST=segfault_20230520_last_good
elif [ "$1" == "first_bad" ]; then
  PYINST=segfault_20230520_first_bad
else
  echo "Invalid argument: '$1'"
  exit 1
fi
set -x
g++ -o main_debugging.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wundef -Wnon-virtual-dtor -Wunused-result -Werror -I/usr/local/google/home/rwgk/forked/pybind11/include -I/usr/local/google/home/rwgk/usr_local_like/$PYINST/include/python3.12 main_debugging.cpp
g++ -o main_debugging -L/usr/local/google/home/rwgk/usr_local_like/$PYINST/lib -rdynamic -O0 -g main_debugging.o -lpython3.12 -lpthread -ldl -lutil
