#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

import os
import stat
import time
FIFO_NAME="american_maid"

if __name__=="__main__":
	num=0
	arr=[1,2,3,4,5,6,7,8,9,0];
	i=0
	
	FIFO_NAME="pipe2"
	try:
		os.mknod(FIFO_NAME,stat.S_IFIFO | 0666, 0)
	except:
		print "pipe existed"
	print "waiting for readers...\n"
	fd = open(FIFO_NAME,'w')
	print "got a reader--type some stuff\n"
	while (i<10):
		time.sleep(10)
		num = fd.write(str(80))
		if num == -1:
			print "write"
		else:
			print "speak: wrote "+str(num)+" bytes\n"
		i=i+1
		fd.flush()

