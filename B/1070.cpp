#include <iostream>
#include <set>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<int, greater<int> > p;
	for(int i = 0;i < n;i++)
	{
		int num;
		cin>>num;
		p.insert(num);
	}
	double sum = *(p.begin());
	for(auto it = next(p.begin());it != p.end();it++)
		sum = (sum + *it)/2;
	cout<<floor(sum)<<endl;
}
