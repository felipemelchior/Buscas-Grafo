#!/bin/bash
g++ -o grafos main.cpp -fopenmp
./grafos com-orkut.ungraph-500K.txt 1