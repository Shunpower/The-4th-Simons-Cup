#!/bin/bash

problem=rhythm
grader_name=grader

g++ -std=c++14 -O2 -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"