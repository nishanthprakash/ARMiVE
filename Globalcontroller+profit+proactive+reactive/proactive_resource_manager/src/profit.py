'''
Created on Mar 7, 2013

@author: sony
'''
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#define NUMGUESTS 4
int NO_DOMU_GUESTS=NUMGUESTS;
char DOMAIN_NAMES[100][100];
int NO_VCPUS=4;
int TOTAL_CAP=400;
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
    ifstream myfile("sla.txt");
    ifstream domainres("res_vec.txt");
    
    int Q=0;
    
    if(myfile.is_open())
      {
        while ( myfile.good() )
        {

    Q++ ;
          getline(myfile,line,'\n');
          if(Q==5)
              break;
          
          revenue.push_back(atoi(line.substr(0,2).c_str()));
         
          penalty.push_back(atoi(line.substr(3,5).c_str()));
         
          alloc_sla_cap.push_back(atoi(line.substr(6,9).c_str()));
         

        }
        myfile.close();

      }
      // MAXIMIZE THE OBJECT FUNCTION (PI+RI)*ALLOC - PI*RI


      sort(rp.begin(),rp.end(),comp_piri);
    
    
    
        getline(domainres,line1,'\n');
        
        
        alloc_req.push_back(atoi(line1.substr(0,3).c_str()));
        
        alloc_req.push_back(atoi(line1.substr(4,7).c_str()));
        
        alloc_req.push_back(atoi(line1.substr(8,11).c_str()));
        
        alloc_req.push_back(atoi(line1.substr(12,15).c_str()));
    


      for(int j=0;j<NO_DOMU_GUESTS;j++)
      {
          rp.push_back(make_pair(penalty[j]+revenue[j],j));          
          rp2.push_back(penalty[j]*alloc_req[j]);
      }
      
      
    
    int total_alloc=0;
    
    
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
          cout << "profit is " << profit <<endl;
}



