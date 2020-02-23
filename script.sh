#!/bin/bash
make re

i=1
total=0
value=0

# if ($1 -eq "-a") then
while [ $i -le $2 ]
do
	# echo $i
	OUTPUT=$(ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l)
	value=$((OUTPUT))
	echo $value
	total=$((total+$value))
	i=$((i+1))
done
# else
	# ./push_swap $ARG
# fi

printf "AVERAGE\n"
echo $((total/$2))