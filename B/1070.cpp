#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int (*p) = new int[n];
	for(int i = 0;i < n;i++) cin>>p[i];
	sort(p,p+n);
	double sum = p[0];
	for(int i = 1;i < n;i++)
		sum = (sum + p[i])/2;
	cout<<floor(sum)<<endl;
	delete [] p;
}
