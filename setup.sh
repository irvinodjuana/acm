#!/bin/bash

mkdir workspace
cd workspace/

for i; do 
    cp ../templates/basic_min.cpp $i.cpp    
done
