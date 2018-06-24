#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	map<int, int> team;
	for(int i = 0;i < n;i++)
    {
        string name;
        int grade;
        cin>>name>>grade;
        team[stoi(name.substr(0,name.find('-')))] += grade;
    }
    cout<<(*max_element(team.begin(),team.end(),[&](const auto a, const auto b)->bool{return a.second < b.second;})).first<<" "<<(*max_element(team.begin(),team.end(),[&](const auto a, const auto b)->bool{return a.second < b.second;})).second<<endl;
}
