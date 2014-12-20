from numpy import var
i=1
class segmentedleastsquares():
    def __init__(self):
        print
        #self.m=[]
        #self.m.append(0)
        #self.m.append(0)
        
        #x=[4,3,4,4,4,5,5,5,5,5,5,5,6,6,6,6,6,3,3,2,3,2,3,3,2,2,3,3,3,3,3,3,3,3,3,3,3,3,4]
        #self.c=4000#var(self.x)/4
        #print self.c
        #for j in range(2,len(self.x)):
            #self.m.append(1000)
        #self.e={}
        #self.n=[None]*len(self.x)
        #self.n[0]=0
        #self.n[1]=1
        #segLstSq(x)
        #self.ans=[]
        
    def mean(self,points,i,j):
        sums=0
        for k in range(i,j):
            sums=sums+points[k]
        return sums/(j-i)
        
    def sqrerror(self,points,i,j):
        err=0
        avg=self.mean(points,i,j)
        for k in range(i,j):
            err=err+pow((points[k]-avg),2)
        return err
    
    def findsegments(self,j):
        #print j
        if(j==1):
            self.ans.append([[0,1],self.mean(self.x,0,1)])
            print 0,1
        elif(j<=0):
            print "returning"
            print self.ans
            return self.ans
        else:
            k=0
            if(k==0):
                l=self.m[k-1]+self.e[k,j]
                i=k
            for k in range(1,j):
                self.n[j]=self.n[k-1]+1
                if (self.m[k-1]+self.e[k,j]+self.c*self.n[j]<l):
                    l=self.m[k-1]+self.e[k,j]+self.c*self.n[j]
                    i=k
            self.ans.append([[i,j],self.mean(self.x,i,j)])
            print i,j
            self.findsegments(i-1)
    
    def segLstSq(self,points):
        self.ans=[]
        self.m=[]
        self.m.append(0)
        self.m.append(0)
        for j in range(2,len(points)):
            self.m.append(1000)
        self.e={}
        self.n=[None]*len(points)
        self.n[0]=0
        self.n[1]=1
        
        self.x=points
        print var(self.x)/4
        self.c=(  var(self.x) * len(self.x) ) / (2 * 2)
        print self.c
        
        for i in range(0,len(points)):
            for j in range(i+1,len(points)):
                #print i,j
                self.e[i,j]=self.sqrerror(points,i,j)
        for j in range(0,len(points)):
            print str(j)+"=",
            for i in range(1,j):
                #print i,j
                self.n[j]=self.n[i-1]+1
                if (self.m[i-1]+self.e[i,j]+self.c*self.n[j]<self.m[j]):
                    self.m[j]=self.m[i-1]+self.e[i,j]+self.c*self.n[j]
                    #print m[j]
        
        for k in range(0,len(self.m)-1):
            print self.m[k],
        
        aans = self.findsegments(len(points)-1)
        #print self.ans
        return self.ans
    
if __name__=="__main__":
    print
    
