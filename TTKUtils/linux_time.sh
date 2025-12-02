#!/bin/sh

find . -exec touch -c -m -d "2025-12-02 12:00" {} \;
