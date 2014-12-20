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
       
	if(frequency[(wt_rules.first).first]<wt_rules.second)
		{
			string str;
			str=(wt_rules.first).first; 
			rules[(wt_rules.first).first]=str.append((wt_rules.first).second);
			frequency[(wt_rules.first).first]=wt_rules.second;
		}
	
}
void initialize(pair<pair<string,string>,int> wt_rules)
{	
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
	ifstream grules("rules.txt");
	if(grules.is_open())
	{
		while(grules.good())
		{
			getline(grules,line,' ');	 
			if(line.size()<5)
				break;		
			wt_rules[make_pair(line.substr(2,3),line.substr(5,2))]++;
		} grules.close();
	}

	for_each(wt_rules.begin(),wt_rules.end(),initialize);
	 
	for_each(wt_rules.begin(),wt_rules.end(),filter);
	 
	for_each(rules.begin(),rules.end(),updaterules);
}

