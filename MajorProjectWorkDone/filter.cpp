#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
map<string,string> rules;
map<string,int> frequency;
ofstream fout("frules.txt");
void filter(pair<pair<string,string>,int> wt_rules)
{
       //cout << wt_rules.second<<endl;
	if(frequency[(wt_rules.first).first]<wt_rules.second)
		{string str;
		 //cout<<"rule" <<(wt_rules.first).first <<"old freq" <<frequency[(wt_rules.first).first]<<"new freq" << wt_rules.second <<endl;
		str=(wt_rules.first).first; 
		rules[(wt_rules.first).first]=str.append((wt_rules.first).second);
		 frequency[(wt_rules.first).first]=wt_rules.second;
                 //for(map<string,int>::iterator it=frequency.begin();it != frequency.end();it++)
		//	cout<< it->first << "----" << it->second<< endl;
		}
	//cout<<endl;
}
void initialize(pair<pair<string,string>,int> wt_rules)
{
	//cout<<"*";
	frequency[(wt_rules.first).first]=0;
}
void updaterules(pair<string,string> r)
{

    fout<<r.second<<endl;
}
int main()
{
pair<string,string> iopair;
map<pair<string,string>,int> wt_rules;
string line;
//cout<<"started"<<endl;
ifstream grules("rules.txt");
if(grules.is_open()){
while(grules.good())
	{
		getline(grules,line,' ');
		//cout<<line<<endl ;		 
		if(line.size()<5)
			break;		
		wt_rules[make_pair(line.substr(2,3),line.substr(5,2))]++;
		//cout<<line.substr(2,3)<<line.substr(5,2)<<endl;
	} grules.close();
}
//for(map<pair<string,string>,int>::iterator it=wt_rules.begin();it != wt_rules.end();it++)
	//cout<<"boot";
 
for_each(wt_rules.begin(),wt_rules.end(),initialize);
 //cout<<"initialised"<<endl;
 for_each(wt_rules.begin(),wt_rules.end(),filter);
 //cout<<"filter"<<endl;
 for_each(rules.begin(),rules.end(),updaterules);
}

