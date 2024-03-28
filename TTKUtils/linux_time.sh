#!/bin/sh  
find . -exec touch -c -m -d "2024-03-28 12:00" {} \;
