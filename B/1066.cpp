#include <iostream>
#include <iomanip>
using namespace std;

void output(int value,int flag)
{
	if(!flag) cout<<setfill('0')<<setw(3)<<value;
	else cout<<" "<<setfill('0')<<setw(3)<<value;
}

int main()
{
	int n,m,nmin,nmax,replacement;
	cin>>n>>m>>nmin>>nmax>>replacement;
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			int temp;
			cin>>temp;
			if(temp >= nmin && temp <= nmax) output(replacement,j);
			else output(temp,j);
		}
		cout<<endl;
	}
}
