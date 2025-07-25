@echo off
echo Generating test cases...

generator.exe 1 equal 1 > test01.in
generator.exe 2 rand 100 > test02.in
generator.exe 5 rand 10 > test03.in
generator.exe 10 incr 100 > test04.in
generator.exe 10 decr 100 > test05.in
generator.exe 10 two 2 > test06.in
generator.exe 11 alternating 1000 > test07.in
generator.exe 50 rand 10000 > test08.in
generator.exe 100 rand 1000000000 > test09.in
generator.exe 200 equal 50 > test10.in
generator.exe 300 rand 1000 > test11.in
generator.exe 400 incr 1000000000 > test12.in
generator.exe 500 decr 1000000000 > test13.in
generator.exe 600 rand 5000 > test14.in
generator.exe 700 two 2 > test15.in
generator.exe 800 alternating 1000000000 > test16.in
generator.exe 1000 rand 100000 > test17.in
generator.exe 5000 rand 1000000000 > test18.in
generator.exe 10000 rand 1000000000 > test19.in
generator.exe 15000 rand 100000 > test20.in
generator.exe 20000 rand 1000000000 > test21.in
generator.exe 50000 rand 1000000000 > test22.in
generator.exe 100000 zigzag 1000000000 > test23.in
generator.exe 150000 rand 1000000000 > test24.in
generator.exe 200000 rand 1000000000 > test25.in

echo All tests generated.
