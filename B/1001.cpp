#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int countn = 0;
    for(;n != 1;)
	{
		countn++;
		if(n % 2) n = (3*n+1)/2;
		else n /= 2;
	}
	cout<<countn<<endl;
}
