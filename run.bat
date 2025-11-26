@echo off

chcp 65001 >nul

gcc -o index index.c && index
