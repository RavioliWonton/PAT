#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(const vector<vector<int> >& tree,const int& number,const int& level,vector<int>& leaf,int& maxlevel)
{
    if(tree[number].size())
        for(int i = 0;i < tree[number].size();i++) dfs(tree,tree[number][i],level + 1,leaf,maxlevel);
    else
    {
        leaf[level]++;
        maxlevel = max(maxlevel,level);
    }
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > tree(100);
	for(int i = 0;i < m;i++)
    {
        int number,countn;
        cin>>number>>countn;
        tree[number].resize(countn);
        for(int j = 0;j < countn;j++) cin>>tree[number][j];
    }
    vector<int> leaf(n,0);
    int maxlevel = -1;
    dfs(tree,1,0,leaf,maxlevel);
    for(int i = 0;i <= maxlevel;i++) cout<<(i ? " " : "")<<leaf[i];
}
