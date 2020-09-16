#if file "numbers" exists
if test ! -f numbers
then
#write 0 to the file
	echo 0 > numbers
fi

#make file "numbers.lock" and then 10 times take the last number from the file "numbers"
# and write to the file "numbers" a number increased by 1 
if ln numbers numbers.lock
	then
	for i in `seq 1 10`;
	do
		n = $(tail -1 numbers)
		n = $((n + 1))
		
		echo $n >> numbers
	done

	#unlock, remove "numbers.lock" file
	rm numbers.lock
fi
