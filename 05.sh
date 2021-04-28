# !/bin/bash

read -p "Enter the number -> " a
i=1

while [ $i -lt 11 ]
do
    echo "$a * $i = `expr $a \* $i`"
    i=`expr $i + 1`
done
