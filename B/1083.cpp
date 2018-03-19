#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<int,int,greater<int> > m;
	for(int i = 1;i <= n;i++)
	{
		int reversen;
		cin>>reversen;
		m[(reversen > i  ? reversen : i) - (reversen > i ? i : reversen)]++;
	}
	for_each(m.begin(),m.end(),[&](pair<int,int> p)->void{if(p.second > 1) cout<<p.first<<" "<<p.second<<"\n";});
}
