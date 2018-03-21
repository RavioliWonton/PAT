#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double maxl = -1,minl = sqrt(2)*20000 + 1;
	int maxn = -1,minn = -1;
	for(int i = 0;i < n;i++)
	{
		int number,x,y;
		cin>>number>>x>>y;
		if(sqrt(pow(x,2)+pow(y,2)) > maxl)
		{
			maxl = sqrt(pow(x,2)+pow(y,2));
			maxn = number;
		}
		if(sqrt(pow(x,2)+pow(y,2)) < minl)
		{
			minl = sqrt(pow(x,2)+pow(y,2));
			minn = number;
		}
	}
	cout<<setfill('0')<<setw(4)<<minn<<" "<<setw(4)<<maxn<<endl;
}
