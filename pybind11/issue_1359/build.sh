#! /usr/bin/bash
set -x
clang++ -o main_attached_to_pr.o -c -std=c++17 -O0 -g -Wall -Wextra -Wconversion -Wcast-qual -Wdeprecated -Wnon-virtual-dtor -Wunused-result -Werror -DPYBIND11_STRICT_ASSERTS_CLASS_HOLDER_VS_TYPE_CASTER_MIX -DPYBIND11_ENABLE_TYPE_CASTER_ODR_GUARD_IF_AVAILABLE -I/usr/local/google/home/rwgk/forked/pybind11/include -I/usr/include/python3.11 main_attached_to_pr.cpp
clang++ -o main_attached_to_pr -rdynamic -O0 -g main_attached_to_pr.o -lpython3.11 -lpthread -ldl -lutil
