import pyeeg
from numpy.random import randn
import csv
import pylab


# output = subprocess.Popen(["xentop"], stdout=subprocess.PIPE).communicate()[0]

with open('usage.csv', 'rb') as csvfile:
    usage = csv.reader(csvfile, delimiter=',', quotechar='|')
    dat=[]	
    for a,b in usage:
      dat.append(int(b))

print len(dat)
data=[]

numsteps =  len(dat)
for i in range(numsteps):
	data.append(dat[i])

#print data

print pyeeg.dfa(data)
pylab.plot(range(numsteps),data,'b')
pylab.show()
