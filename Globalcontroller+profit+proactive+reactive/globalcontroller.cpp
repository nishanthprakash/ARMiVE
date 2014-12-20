#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#define NUMGUESTS 2
int NO_DOMU_GUESTS=2;
char DOMAIN_NAMES[100][100];
int NO_VCPUS=4;
int TOTAL_CAP=4;
//int WEIGHTS[10];
using namespace std;


int comp_piri(pair<int,int> a,pair<int,int> b)
{
    if(a.first>b.first)
    return true;
    else
    return false;
}

void perform_cpu_allocation ( vector<int> alloc)
{
    char command[150];
    int i=0;
    for(vector<int>::iterator k=alloc.begin();k<alloc.end()&&i<2;k++)
    {
        sprintf(command,"xm sched-credit -d %s -w %d", DOMAIN_NAMES[i],*k);
        system(command);
        printf("%s\n",command);
	i++;
    }
}
int main()
{
    strcpy(DOMAIN_NAMES[0],"fedora");
    strcpy(DOMAIN_NAMES[1],"fedora2");
    string line,line1,line2;
    vector<int> domains;
    vector<int> weight_req;
    vector<int> cap_req;
    vector<int> penalty;
    vector<int> revenue;
    vector<int> alloc_sla;
    vector<int> alloc_cap;
    vector<pair<int,int> > PR;
    vector<int> alloc_weight;
    int profit;
    //ifstream myfile("sla.txt");
    ifstream domain1res("res_vec1.txt");
    ifstream domain2res("res_vec2.txt");
    /*if(myfile.is_open())
      {
        while ( myfile.good() )
        {

          getline(myfile,line," ");

          revenue.push_back(int(*(line.substr(0,2).begin())));
          penalty.push_back(int(*(line.substr(3,5).begin())));

        }
        myfile.close();

      }*/
      // MAXIMIZE THE OBJECT FUNCTION (PI+RI)*ALLOC - PI*RI

      for(int j=0;j<domains.size();j++)
      {
          PR.push_back(make_pair(penalty[j]+revenue[j],j));
      }

      sort(PR.begin(),PR.end(),comp_piri);
	
	for(int y=0;y<10;y++)
		alloc_weight.push_back(256);

     perform_cpu_allocation(alloc_weight);

      while(domain1res.good() && domain2res.good())
	{

		getline(domain1res,line1,' ');
		getline(domain2res,line2,' ');
		weight_req.push_back(atoi(line1.c_str()));
		weight_req.push_back(atoi(line2.c_str()));
		
		 /*for(vector<pair<int,int> >::iterator k=PR.begin();k<PR.end();k++)
		      {
			  if(TOTAL_CAP>0)
			  {
			      if(weight_req[k->second ]<alloc_sla[k->second])
			      {
				    alloc_cap[k->second] = weight_req[k->second];
				    TOTAL_CAP=TOTAL_CAP-weight_req[k->second];

			      }
			      else
			      {
				    alloc_cap[k->second] = alloc_sla[k->second];
				    TOTAL_CAP=TOTAL_CAP-alloc_sla[k->second];

			      }
			      profit=profit+(k->first * alloc_cap[k->second])-cap_req[k->second]*penalty[k->second];
			  }
		      }
		*/
		for(int f=0;f<2;f++)
		{
			int sum=0;
			alloc_weight[f]=weight_req[f]*alloc_weight[f]/200;          //normailse
			/*for(int t=0;t<2;t++)
				sum=sum+alloc_weight[t];
				alloc_weight[f]=alloc_weight[f]/sum*256;
*/
		}

		perform_cpu_allocation(alloc_weight);
	}

}


