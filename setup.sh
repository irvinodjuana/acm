#!/bin/bash

mkdir workspace
cd workspace/

for i; do 
    cp ../templates/basic.cpp $i.cpp    
done
