#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct {
	double grade;
	int population;
} attribution;

typedef struct {
	string name;
	attribution property;
} company;

struct companyCompare {
	bool operator() (const company& a, const company& b) const {
		if(a.property.grade != b.property.grade) return a.property.grade > b.property.grade;
		else if(a.property.population != b.property.population) return a.property.population < b.property.population;
		else return a.name < b.name;
	}
};

int main()
{
	int n;
	scanf("%d",&n);
	map<string, attribution> teams;
	for(int i = 0;i < n;i++)
	{
		string number,companyn;
		number.resize(6);
		companyn.resize(6);
		double grade;
		auto f = [&](char a)->double {
					switch(a)
					{
							case 'B':return -1.5;break;
							case 'A':return 1.0;break;
							case 'T':return 1.5;break;
					}
					return 0.0;
		};
		scanf("%s %lf %s",&number[0],&grade,&companyn[0]);
		transform(companyn.begin(),companyn.end(),companyn.begin(),::tolower);
		teams[companyn].grade += (f(number.front()) > 0 ? f(number.front())*grade : grade / -f(number.front()));
		teams[companyn].population++;
	}
	set<company, companyCompare> result;
	for(auto& corporation : teams) result.insert({corporation.first,{trunc(corporation.second.grade), corporation.second.population}});
	printf("%Lu\n",result.size());
	int rankn = 1;
	for(auto it = result.begin();it != result.end();it++)
	{
		if(it != result.begin() && (*it).property.grade != (*prev(it)).property.grade) rankn = distance(result.begin(),it) + 1;
		printf("%d %s %.lf %d\n",rankn,(*it).name.c_str(),(*it).property.grade,(*it).property.population);
	}
}
