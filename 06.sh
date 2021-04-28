# !/bin/bash

read -p "Enter your basic salary -> " basicSalary

if [ $basicSalary -lt 1500 ]
then
    hra=`expr $basicSalary \* 30 / 100`
    da=`expr $basicSalary \* 20 / 100`
    grossSalary=`expr $basicSalary + $hra + $da`
else
    hra=`expr $basicSalary \* 40 / 100`
    da=2000
    grossSalary=`expr $basicSalary + $hra + $da`
fi

echo "Gross salary -> $grossSalary"


