#!/bin/bash

cd workspace/
GCC="g++ -std=c++11 -O2 -Wall"

for i; do 
    $GCC $i.cpp -o $i.o
done
