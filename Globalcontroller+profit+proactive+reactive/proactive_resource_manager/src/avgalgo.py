#!/net/python/bin/python
import pylab as p
import numpy as num
import os
from segmentedleastsquares import segmentedleastsquares
from pearson_correlation import pearson_corr
INTERVAL_LENGTH=180
TIME_INTERVAL=1440
NUM_DAYS_DATA=4
FIFO_NAME="pipe0"
ipfile = open("training_req_data.txt",'r')
#try:
#	os.mknod(FIFO_NAME,stat.S_IFIFO | 0666, 0)
#except:
#	print "pipe existed"
		
fd = open(FIFO_NAME,'w')
		
a=[] 
req_per_min = ipfile.readline()
while req_per_min is not None and req_per_min is not '':
	try:
		print int(req_per_min)
		a.append(int(req_per_min))
		req_per_min = ipfile.readline()
	except:
		break
	
a=a[0:5758]

y=[]
yy=[]
for i in range(len(a)):
	y.append(i)

for i in range(len(a)/INTERVAL_LENGTH):
	for j in range(INTERVAL_LENGTH):
		yy.append(i)
		
k=0
avg =[]
avgone=[]
sign=[]
training_size=NUM_DAYS_DATA*1440
window_size=TIME_INTERVAL

n=training_size/window_size

signature=[None]*n
for k in range(n):
	signature[k]=[]


k=0
# switch between mean per 3hour and dynamic programming
min_changes_req = True
if min_changes_req is True:
	sid=0
	sls=segmentedleastsquares()
	for k in range (0,training_size,window_size):
		signature[sid]=sls.segLstSq(a[k:k+window_size])
		print "got signature for "+str(sid+1)+" th day"
		for j in range(len(signature[sid])-1,-1,-1):
			for t in range(1440*sid+signature[sid][j][0][0],1440*sid+signature[sid][j][0][1]+1):
				avg.append(signature[sid][j][1])
			avgone.append(signature[sid][j][1])
		sign.append(avgone)
		avgone=[]
		sid=sid+1
	for k in range(len(signature)):
		print "k="+str(k)
		print signature[k]
	avg.append(0)
	print avg
	print len(avg)
	print len(y)
	p.plot(y,a)
	for u in range(len(avg),len(y)):
		avg.append(0)
	#p.plot(days,marks)
	p.plot(y,avg)
	p.show()
else:
	#days=[1440,1440,1440,1440,1440,2880,2880,2880,2880,2880,4320,4320,4320,4320,4320,5760,5760,5760,5760,5760]
	#marks=[500,400,300,200,100,500,400,300,200,100,500,400,300,200,100,500,400,300,200,100]
	tmp=[]
	
	for i in range(len(a)):
		if(i%8==0 and i==0):
			sign.append(avgone[i-8:i])
		if((k)%INTERVAL_LENGTH!=0 or k==0):
			tmp.append(a[k])
			k=k+1
		else:
			for j in range(INTERVAL_LENGTH):
				avg.append(sum(tmp) / len(tmp))
			avgone.append(sum(tmp) / len(tmp))
			tmp = []
			tmp.append(a[k])
			k=k+1
	
	print avgone
	print len(y)
	print len(avg)
	for u in range(len(avg),len(y)):
		avg.append(0)
	
	if pearson_corr(sign) is True:
		print "Strong pattern found"
	elif pearson_corr(sign) is False:
		print "Weak pattern found"
	else:
		print "error"
	z=[]
	
	# predicting over this interval
	 
	for i in range(5760,7200):
		z.append(i)
	
	predict=[]
	for j in range(8):
		s=0	
		for k in range(4):
			s=s+avgone[8*k+j]
		for o in range(180):
			predict.append(s/4)
		
	p.plot(z,predict)
	p.plot(y,a)
	#p.plot(days,marks)
	p.plot(y,avg)
	p.show()
