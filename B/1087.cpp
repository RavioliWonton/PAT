#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n;
	cin>>n;
	set<int> p;
	for(int i = 1;i <= n;i++) p.insert(i/2+i/3+i/5);
	cout<<p.size()<<endl;
}
