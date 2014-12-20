
i=5000 

while [ $i -le 50000 ]
do	
	httperf --hog --server 10.100.14.172 --num-conn 100000 --ra $i --timeout 5
	i=`expr $i + 5000`
	
done

