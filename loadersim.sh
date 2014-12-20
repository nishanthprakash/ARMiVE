max_iter=

while [ $number -le $max_iter ]
do


	num_conn = `grep ${VALUE} inputfile.csv | cut -d, -f${INDEX} | head -{$number} | tail -1`

	httperf --server hostname --port 80 --uri /test.html --rate {$num_conn} --num-conn {$num_conn} --num-call 1 --timeout 5

	number=`expr $number + 1`

done