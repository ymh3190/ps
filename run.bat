@echo off

chcp 65001 >nul

gcc -o main main.c && main
