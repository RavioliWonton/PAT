#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

int findg(const int& key,vector<int>& v)
{
    if(v[key] != key) v[key] = findg(v[key],v);
    return v[key];
}

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	map<int,set<int> > graph;
	for(int i = 0;i < m;i++)
    {
        int from,to;
        cin>>from>>to;
        graph[from].insert(to);
        graph[to].insert(from);
    }
    for(int i = 0;i < k;i++)
    {
        int city;
        cin>>city;
        vector<int> temp;
        for(int i = 0;i < n;i++) temp.push_back(i + 1);
        for(int i = 1;i <= n && i != city;i++)
        {
            for(int j = 1;j <= n && j != city;j++)
                if(graph[i].count(j)) temp[findg(j,temp)] = findg(i,temp);
        }
        int countn = 0;
        for(int i = 1;i <= n;i++)
            if(temp[i] == i) countn++;
        cout<<(countn < 2 ? 0 : (n - 1 == 1 ? 0 : countn - 2))<<endl;
    }
}
