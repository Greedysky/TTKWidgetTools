#!/bin/sh

find . -exec touch -c -m -d "2025-12-02 00:00" {} \;
