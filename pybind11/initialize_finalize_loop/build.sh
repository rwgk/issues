#! /usr/bin/bash
set -e
set -x
MAIN=initialize_finalize_loop
clang++ -o $MAIN.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -Werror -DPYBIND11_STRICT_ASSERTS_CLASS_HOLDER_VS_TYPE_CASTER_MIX -DPYBIND11_ENABLE_TYPE_CASTER_ODR_GUARD_IF_AVAILABLE -I$HOME/forked/pybind11/include -I/usr/include/python3.10 $MAIN.cpp
clang++ -o $MAIN -rdynamic -O0 -g $MAIN.o -lpython3.10 -lpthread -ldl -lutil
