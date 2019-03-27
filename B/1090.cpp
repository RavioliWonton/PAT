//这破题肯定又要用稀疏表……
//还不给用，会内存崩掉。

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<bitset<99999> > incompatible(99999);
	for(int i = 0;i < n;i++)
    {
        int first,second;
        cin>>first>>second;
        incompatible[first][second] = incompatible[second][first] = 1;
    }
    for(int i = 0;i < m;i++)
    {
        int k;
        cin>>k;
        vector<int> input(k);
        for(int j = 0;j < k;j++) cin>>input[j];
        bool flag = true;
        for(auto it = input.begin();it != input.end();it++)
        {
            for(auto it2 = next(it);it2 != input.end();it2++)
                if(incompatible[*it][*it2]) {flag = false;break;}
            if(!flag) break;
        }
        cout<<(flag ? "Yes\n" : "No\n");
    }
}
