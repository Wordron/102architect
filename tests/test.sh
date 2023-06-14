#!/bin/bash

make
clear

echo -e "\033[92mSimple test -t:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Translation along vector (-1, 1)"; echo "1.00    0.00    -1.00"; echo "0.00    1.00    1.00"; echo "0.00    0.00    1.00"; echo "(5.00, 0.00) => (4.00, 1.00)";
echo -e "\033[31mGot :\033[00m"
./102architect 5 0 -t -1 1

echo -e "\033[92mSimple test -z:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Scaling by factors -1 and 1"; echo "-1.00    0.00    0.00"; echo "0.00    1.00    0.00"; echo "0.00    0.00    1.00"; echo "(2.00, 2.00) => (-2.00, 2.00)";
echo -e "\033[31mGot :\033[00m"
./102architect 2 2 -z -1 1

echo -e "\033[92mSimple test -r:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Rotation by a 90 degree angle"; echo "0.00    -1.00    0.00"; echo "1.00    0.00    0.00"; echo "0.00    0.00    1.00"; echo "(1.00, 0.00) => (0.00, 1.00)";
echo -e "\033[31mGot :\033[00m"
./102architect 1 0 -r 90

echo -e "\033[92mSimple test -s:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Reflection over an axis with an inclination angle of 270 degrees"; echo "-1.00    0.00    0.00"; echo "0.00    1.00    0.00"; echo "0.00    0.00    1.00"; echo "(3.00, -1.00) => (-3.00, -1.00)";
echo -e "\033[31mGot :\033[00m"
./102architect 3 -1 -s 270

echo -e "\033[92mtest -t-z-r-s:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Translation along vector (2, 3)"; echo "Scaling by factors 1 and -2"; echo "Rotation by a 45 degree angle"; echo "Reflection over an axis with an inclination angle of 30 degrees"; echo "0.97    -0.52    0.38"; echo "0.26    1.93    6.31"; echo "0.00    0.00    1.00"; echo "(1.00, 2.00) => (0.31, 10.44)";
echo -e "\033[31mGot :\033[00m"
./102architect 1 2 -t 2 3 -z 1 -2 -r 45 -s 30

echo -e "\033[92mSimple test check error -s:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84";
echo -e "\033[31mGot :\033[00m"
./102architect 3 a -s 270
echo $?

echo -e "\033[92mSimple test check error -t:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84";
echo -e "\033[31mGot :\033[00m"
./102architect 3 a -t -1 1
echo $?

echo -e "\033[92mSimple test check error too many arguments -t:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84";
echo -e "\033[31mGot :\033[00m"
./102architect 3 2 -t -1 1 6
echo $?

echo -e "\033[92mSimple test check error too many arguments with multiple transformations:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84";
echo -e "\033[31mGot :\033[00m"
./102architect 3 2 -t -1 1 -r 60 5
echo $?
