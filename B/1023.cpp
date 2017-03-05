#include <iostream>
using namespace std;
int main()
{
	int n0,n;bool flag = true;
	cin>>n0;
	for(int i = 1;cin>>n;i++)
    {
        if(n != 0 && flag)
        {
            cout<<i;
            for(int j = 0;j < n0;j++)
                cout<<"0";
            for(int j = 0;j < n - 1;j++)
                cout<<i;
            flag = false;
        }
        else if(n != 0 && !flag)
        {
            for(int j = 0;j < n;j++)
                cout<<i;
        }
    }
    cout<<endl;
}
