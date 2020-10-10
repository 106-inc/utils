#!/bin/bash

py_filename="csv_to_tex.py"
if [ -e $py_filename ] # Check if the python source file exists
then python3 $py_filename $* 
else
echo "ctx: error: cannot found file '$py_filename'"
fi

