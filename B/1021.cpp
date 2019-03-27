#include <iostream>
#include <string>
#include <vector>
using namespace std;

auto judge = [&](char c)->int
{
    if(isdigit(c)) return c-'0';
    else return -1;
};

int main()
{
	string a;
	cin>>a;
    vector<int> p(10,0);
    for(auto& c : a)
        if(judge(c) != -1) p[judge(c)]++;
    for(auto it = p.begin();it != p.end();it++)
        if(*it) cout<<distance(p.begin(),it)<<":"<<*it<<endl;
}
