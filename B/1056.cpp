#include <iostream>
using namespace std;
int main()
{
	int n,sum = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        sum += temp*11*(n - 1);
    }
    cout<<sum<<endl;
}
