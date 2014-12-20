#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define NUMGUESTS 4

int NO_DOMU_GUESTS=NUMGUESTS;
char DOMAIN_NAMES[100][100];
int NO_VCPUS=4;
int TOTAL_CAP=400;
int INT_BTN_ALLOC_SEC=60;
int alloc[5]={0};

using namespace std;


int comp_piri(pair<int,int> a,pair<int,int> b)
{
    if(a.first>b.first)
    return true;
    else
    return false;
}


int main()
{


  int n= NO_DOMU_GUESTS;
  char fifo_name[50];
  int fd[NO_DOMU_GUESTS];
  int i=0;
  for(i=0;i<NO_DOMU_GUESTS;i++)
    {
      sprintf(fifo_name,"%s%d","pipe",i);
      mknod(fifo_name,S_IFIFO | 0666, 0);
      fd[i]=open(fifo_name, O_RDONLY);
    }
    
    // strcpy(DOMAIN_NAMES[0],"fedora");
    // strcpy(DOMAIN_NAMES[1],"fedora2");
    string line,line1,line2;
    vector<int> domains;
    vector<int> penalty;
    vector<int> revenue;
    vector<int> alloc_sla_cap;
    vector<int> alloc_req;
    vector<pair<int,int> > rp;
    vector<int> rp2;
   
    
    int profit=0;
    char res_domu_buf[300];
    int stop=0;
    int num[NO_DOMU_GUESTS];

    ifstream sla_cfg("sla.txt");
    ifstream domainres("res_vec.txt");
    
       
    int Q=0;
    int x=0;

    //Get the sla details
    printf("LOG:Waiting for LC\n");
    if(sla_cfg.is_open())
      {
        while ( sla_cfg.good() )
        {

	Q++ ;
          getline(sla_cfg,line,'\n');
          if(Q==5)
          	break;
          
          revenue.push_back(atoi(line.substr(0,2).c_str()));
         
          penalty.push_back(atoi(line.substr(3,5).c_str()));
         
          alloc_sla_cap.push_back(atoi(line.substr(6,9).c_str()));
         

        }
        sla_cfg.close();

      }
      // MAXIMIZE THE OBJECT FUNCTION (PI+RI)*ALLOC - PI*RI
      for(int j=0;j<NO_DOMU_GUESTS;j++)
      {
	rp.push_back(make_pair(penalty[j]+revenue[j],j));
      }

      sort(rp.begin(),rp.end(),comp_piri);
	
      /* for(int j=0;j<NO_DOMU_GUESTS;j++)
	{
	  rp.push_back(make_pair(penalty[j]+revenue[j],j));
	  rp2.push_back(penalty[j]*alloc_req[j]);
	}
      */
      // sort(rp.begin(),rp.end(),comp_piri);
	
      /*	
      getline(domainres,line1,'\n');
		
		
      alloc_req.push_back(atoi(line1.substr(0,3).c_str()));
		
      alloc_req.push_back(atoi(line1.substr(4,7).c_str()));
		
      alloc_req.push_back(atoi(line1.substr(8,11).c_str()));
		
      alloc_req.push_back(atoi(line1.substr(12,15).c_str()));
      */
      
      /* get the real time resource usage and make allocation */

     
      while(1)	
	{
	  
	  stop=0;
	  //sleep(INT_BTN_ALLOC_SEC);
	  for(i=0;i<NO_DOMU_GUESTS;i++)
            {
	      printf("LOG:Waiting for LC%d\n",i);

	      if ((num[i] = read(fd[i], res_domu_buf, 300)) == -1)
		perror("read");
	      else 
		{
		  res_domu_buf[num[i]] = '\0';
		  printf("LOG:LC%d: requests %s CPU resources\n",i, res_domu_buf);
		  alloc_req.push_back(atoi(res_domu_buf));
		  bzero(res_domu_buf,sizeof(res_domu_buf));
		}	         

	      if(num[i]<=0)
		{
		  stop=1;
		  break;
		}
	     }
	  
	  if(stop)
	     {
	       printf("ERROR: Did not get cpu resource req estimate from LC %d\n",x);
	       break;
	     }

	  for(int j=0;j<NO_DOMU_GUESTS;j++)
	    {
	      rp2.push_back(penalty[j]*alloc_req[j]);
	    }
  
	  
      
	  int total_alloc=0;	
	  profit = 0;
	  for(vector<pair<int,int> >::iterator k=rp.begin();k<rp.end();k++)
	      {
		
		      if(alloc_req[k->second ]>alloc_sla_cap[k->second])
		      {
		      		alloc_req[k->second ]=alloc_sla_cap[k->second];
		      }
	
		      if(TOTAL_CAP-total_alloc>alloc_req[k->second])
		      {
	
				alloc[k->second] = alloc_req[k->second];    //allocation
	
				total_alloc+=alloc[k->second];
	
				    
		        	profit=profit+(k->first * alloc[k->second])-rp2[k->second];
		      }
		      else
		      {
		      		alloc[k->second]=TOTAL_CAP-total_alloc;
		      		profit=profit+(k->first * alloc[k->second])-rp2[k->second] ;
		      		break;
		      		
		      }
	       }
	       for(int h=0;h<4;h++)
	       cout<<alloc[h]<<endl;
	       cout << "LOG:profit is \n" << profit <<endl;
	       alloc_req.clear();
	}
}



