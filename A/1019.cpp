#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n,b;
	cin>>n>>b;
	vector<int> v;
	if(!n) v.push_back(0);
    for(;n >= 1;)
	{
		v.push_back(n%b);
		n /= b;
	}
	vector<int> v1 (ceil((double)(v.size())/2));vector<int> v2 (ceil((double)(v.size())/2));
	copy(v.begin(),v.begin()+ceil((double)(v.size())/2),v1.begin());
	copy(v.begin()+floor((double)(v.size())/2),v.end(),v2.begin());
	reverse(v2.begin(),v2.end());
	if(v1 == v2) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	for(auto it = v.rbegin();it != v.rend();it++)
	{
		if(it == v.rbegin()) cout<<*it;
		else cout<<" "<<*it;
	}
	cout<<endl;
}
