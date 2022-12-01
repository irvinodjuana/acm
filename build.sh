#!/bin/bash

cd workspace/
GCC="g++ -std=c++11 -O2 -Wall"
# GCC="g++ -x c++ -g -O2 -std=gnu++17"

for i; do 
    $GCC $i.cpp -o $i.o
done
