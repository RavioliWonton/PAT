#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	int m;
	cin>>m;
	for(int i = 0;i < m;i++)
	{
		int k;
		cin>>k;
		bool flag = false;
		for(int n = 1;n <= 10;n++)
		{
			if(n*k*k % (int)pow(10,to_string(k).size()) == k)
			{
				cout<<n<<" "<<n*k*k<<"\n";
				flag = true;
				break;
			}
		}
		if(!flag) cout<<"No\n";
	}
}
