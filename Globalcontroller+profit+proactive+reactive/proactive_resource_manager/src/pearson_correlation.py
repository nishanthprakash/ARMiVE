'''
Created on Mar 7, 2013

@author: sony
'''
class pearson_corr():
    def __init__(self,daily_usage,num_days):
        wnds=num_days
        corr_coeff=[]
        for i in range(0,wnds):
            for j in range(i,wnds):
                xarr = daily_usage[i]
                yarr = daily_usage[j];
                corr_coeff.append(self.Calculate_Correlation(xarr,yarr))
            
        print corr_coeff
                
        for j in range(len(corr_coeff)):
            if (corr_coeff[j]<0.85):
                return False;
        return True
        

    def CalculateMean(self,value):
        sum = 0;
        for i in range(0,max):
            sum = sum + value[i];
        return (sum / max);
        
        
    def CalculateVariance(self,value):
        mean = self.CalculateMean()
        temp = 0;
        for i in range(0,max):
            temp = temp + (value[i] - mean) * (value[i] - mean)
        return temp / max;
    
    def Calculate_StdDeviation(self,value):
        return pow(self.CalculateVariance(value),0.5)
    
    def Calculate_Covariance(self,X,Y):
        xmean = self.CalculateMean(X);
        ymean = self.CalculateMean(Y);
        total = 0;
        for i in range(0,max):
            total += (X[i] - xmean) * (Y[i] - ymean);
        return total / max;
    
        
    def Calculate_Correlation(self,X,Y):
        cov = self.Calculate_Covariance();
        correlation = cov / (self.Calculate_StdDeviation(X) * self.Calculate_StdDeviation(Y));
        return correlation;
        
        

