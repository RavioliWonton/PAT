//不改了，明天再说。

#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	double grade;
	int population;
} company;

int main()
{
	int n;
	cin>>n;
	vector<company> v;
	auto f = [&](char a)->double {
					switch(a)
					{
							case 'B':return -1.5;break;
							case 'A':return 1.0;break;
							case 'T':return 1.5;break;
					}
					return 0;
	};
	for(int i = 0;i < n;i++)
	{
		string number,companyn;
		double grade;
		cin>>number>>grade>>companyn;
		transform(companyn.begin(),companyn.end(),companyn.begin(),::tolower);
		auto it = find_if(v.begin(),v.end(),[&](company a)->bool{return a.name == companyn;});
		if(it != v.end())
		{
			(*it).grade += (f(number.front()) > 0 ? f(number.front())*grade : grade / -f(number.front()));
			(*it).population++;
		}
		else v.push_back({companyn,(f(number.front()) > 0 ? f(number.front())*grade : grade / -f(number.front())),1});
	}
	for_each(v.begin(),v.end(),[&](company a)->void{a.grade = trunc(a.grade / (double)a.population);});
	sort(v.begin(),v.end(),[&](company a,company b)->bool{
			if(a.grade != b.grade) return a.grade > b.grade;
			else if(a.population != b.population) return a.population < b.population;
			else return a.name < b.name;
		});
	cout<<v.size()<<endl;
	int rankn = 1,pastpopulation = -1;
	double pastgrade = -1.0;
	cout.setf(ios::fixed);
	cout.precision(0);
	for(auto it = v.begin();it != v.end();it++)
	{
		if((int)pastgrade != (int)(*it).grade && pastpopulation != (*it).population) rankn = distance(v.begin(),it) + 1;
		cout<<rankn<<" "<<(*it).name<<" "<<(*it).grade<<" "<<(*it).population<<endl;
		pastgrade = (*it).grade;
		pastpopulation = (*it).population;
	}
}
