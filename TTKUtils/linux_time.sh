#!/bin/sh  
find . -exec touch -c -m -d "2023-04-15 12:00" {} \;
