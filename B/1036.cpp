#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a;char b;
	cin>>a>>b;
    for(int i = 0;i < (int)round(((double)a)/2);i++)
    {
        if(i == 0 || i == (int)round(((double)a)/2) - 1)
            for(int j = 0;j < a;j++)
                cout<<b;
        else
        {
            cout<<b;
            for(int j = 0;j < a - 2;j++) cout<<" ";
            cout<<b;
        }
        cout<<endl;
    }
}
