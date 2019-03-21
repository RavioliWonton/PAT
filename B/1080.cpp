#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct {
	int devgrade;
	int midtermgrade;
	int finalgrade;
} grade;

typedef struct {
	string id;
	grade coursegrade;
	double overallgrade;
} student;

int main()
{
	int p,m,n;
	cin>>p>>m>>n;
	map<string, grade, greater<string> > input;
	for(int i = 0;i < p;i++)
	{
		string id;
		int devgrade;
		cin>>id>>devgrade;
		if(devgrade >= 0 && devgrade <= 900) input.insert(pair<string, grade>(id,{devgrade, -1, -1}));
	}
	for(int i = 0;i < m;i++)
	{
		string id;
		int midtermgrade;
		cin>>id>>midtermgrade;
		if(midtermgrade >= 0 && midtermgrade <= 100) input[id].midtermgrade = midtermgrade;
	}
	for(int i = 0;i < n;i++)
	{
		string id;
		int finalgrade;
		cin>>id>>finalgrade;
		if(finalgrade >= 0 && finalgrade <= 100) input[id].finalgrade = finalgrade;
	}
	auto studentCompare = [&](const student& a, const student& b)->bool{
		if(a.overallgrade != b.overallgrade) return a.overallgrade > b.overallgrade;
		else return a.id < b.id;
	};
	set<student, decltype(studentCompare)> result;
	for(auto& it : input)
	{
		if((it.second).devgrade >= 200)
		{
			double overallgrade = 0.0;
			if((it.second).midtermgrade > (it.second).finalgrade) overallgrade = 0.4*(it.second).midtermgrade + 0.6*(it.second).finalgrade;
			else overallgrade = (it.second).finalgrade;
			if(round(overallgrade) >= 60.0) result.insert({it.first, it.second, round(overallgrade)});
		}
	}
	for_each(result.begin(), result.end(), [&](student passedstudent)->void{
		cout<<passedstudent.id<<" "
			<<passedstudent.coursegrade.devgrade<<" "
			<<passedstudent.coursegrade.midtermgrade<<" "
			<<passedstudent.coursegrade.finalgrade<<" "
			<<passedstudent.overallgrade<<"\n";
	});
}
