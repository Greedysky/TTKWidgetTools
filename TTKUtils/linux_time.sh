#!/bin/sh  
find . -exec touch -c -m -d "2025-05-05 12:00" {} \;
