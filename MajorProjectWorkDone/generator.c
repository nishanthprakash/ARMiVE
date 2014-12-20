#include <string.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char* argv[])
    {
        char domain_class[5];
        char inp[100];
	if(argc<2) printf("Screw you enter the number of CPUs damn it !!!\n");
	float a=atof(argv[1]);
	//printf("%f",a);
	system("rm cpustat.txt rules.txt");
	//system("xentop -b -i 5 | grep \"fedora2\" >> cpustat1.txt");
	system("xentop -b -i 120 -d 1 | grep \"fedora \" | cut -f 16-18 -d \" \"  >> cpustat.txt");	
	//system("rm cpustat1.txt");	
	system("touch rules.txt");

	FILE *cpuFile = fopen("cpustat.txt","r");
	FILE *Fileout = fopen("rules.txt","w");
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
                i[j]=a*100 - atof(inp);
                fgets(inp,100,cpuFile);
		
            }
            else
            {
                i[j]=a*100 - atof(inp);
                fgets(inp,100,cpuFile);

            }
            j++;
        }
        while(1)
        {
            i[4]=a*100 - atof(inp);
           
            for(k=0;k<5;k++)
            {
            if (i[k]>=0*a && i[k]<10*a)
                domain_class[k]=0;
            if (i[k]>10*a && i[k]<20*a)
                domain_class[k]=1;
            if (i[k]>20*a && i[k]<30*a)
                domain_class[k]=2;
            if (i[k]>30*a && i[k]<40*a)
                domain_class[k]=3;
            if (i[k]>40*a && i[k]<50*a)
                domain_class[k]=4;
            if (i[k]>50*a && i[k]<60*a)
                domain_class[k]=5;
            if (i[k]>60*a && i[k]<70*a)
                domain_class[k]=6;
            if (i[k]>70*a && i[k]<80*a)
                domain_class[k]=7;
            if (i[k]>80*a && i[k]<90*a)
                domain_class[k]=8;
            if (i[k]>90*a && i[k]<=100*a)
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
