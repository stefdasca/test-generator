@echo off
setlocal EnableDelayedExpansion
for /l %%i in (1,1,25) do (
    set num=00%%i
    set num=!num:~-2!
    echo Running test case !num!...
    solution.exe < test!num!.in > test!num!.out
)
pause