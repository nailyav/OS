#write 0 to the file "rNumbers"
if test ! -f rNumbers
then
	echo 0 > rNumbers
fi

#10 times take the last number from the file, increase it by 1 and then write it to the file
for i in `seq 1 10`;
do
	n = $(tail -l rNumbers)
	n = $((n + 1))

	echo $n >> rNumbers
done
