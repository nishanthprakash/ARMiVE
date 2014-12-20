#include <string.h>
#include <stdlib.h>
#include <stdio.h>

main()
    {
        FILE *cpuFile = fopen("cpustat.txt","r");
	FILE *Fileout = fopen("rules.txt","w");
        char domain_class[5];
        char inp[100];
	system("top -b -n 10  | grep \"Cpu\" | cut -f 4 -d \",\" | cut -f 1 -d \"%\" >> cpustat.txt");
        if (cpuFile == NULL)
            perror ("Error opening file");
        else
        {
            fgets(inp,100,cpuFile);
	
        }
        float i[5];
	int j=0,k;
        while(j!=5)
        {
            if(j<3)
            {
                i[j]=100 - atof(inp);
                fgets(inp,100,cpuFile);
		
            }
            else
            {
                i[j]=100 - atof(inp);
                fgets(inp,100,cpuFile);

            }
            j++;
        }
        while(1)
        {
            i[4]=100 - atof(inp);
           
            for(k=0;k<5;k++)
            {
            if (i[k]>0 && i[k]<10)
                domain_class[k]=0;
            if (i[k]>10 && i[k]<20)
                domain_class[k]=1;
            if (i[k]>20 && i[k]<30)
                domain_class[k]=2;
            if (i[k]>30 && i[k]<40)
                domain_class[k]=3;
            if (i[k]>40 && i[k]<50)
                domain_class[k]=4;
            if (i[k]>50 && i[k]<60)
                domain_class[k]=5;
            if (i[k]>60 && i[k]<70)
                domain_class[k]=6;
            if (i[k]>70 && i[k]<80)
                domain_class[k]=7;
            if (i[k]>80 && i[k]<90)
                domain_class[k]=8;
            if (i[k]>90 && i[k]<100)
                domain_class[k]=9;
	
	    fprintf(Fileout,"%d",domain_class[k]);
            }
	    fprintf(Fileout,"\n");
	    if(!fgets(inp,100,cpuFile))
		break;
	
        i[0]=i[1];
	i[1]=i[2];
	i[2]=i[3];
	i[3]=i[4];
        }
}
