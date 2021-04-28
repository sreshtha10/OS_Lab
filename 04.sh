# !/bin/bash

read -p "Enter the first number -> " a
read -p "Enter the second number -> " b


echo "a + b = `expr $a + $b`"
echo "a - b = `expr $a - $b`"
echo "a * b = `expr $a \* $b`"
echo "a / b = `expr $a / $b`"
