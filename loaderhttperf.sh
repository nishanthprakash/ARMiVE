max_iter=720
number=0
while [ $number -le $max_iter ]
do
   num_conn=`cat inputfile.csv | head -$number | tail -1 | sed 's/\\r/|/' | cut -d '|' -f 1`
   #echo "\"$num_conn\"" 
   httperf --server 10.100.14.155 --port 80 --uri /WebCalendar-1.2.6/month.php --rate $num_conn --num-conn $num_conn --num-call 1 --timeout 5 | grep "Reply time" | cut -d" " -f5 2> /dev/null
   number=`expr $number + 1`
done
