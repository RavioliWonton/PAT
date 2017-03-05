#include <iostream>
using namespace std;
int main()
{
    int n,n1,n2,n3;
    cin>>n;
    n1 = n/100;
    n2 = (n-100*n1)/10;
    n3 = n-100*n1-10*n2;
    for(int i = 0;i < n1;i++)
        cout<<"B";
    for(int j = 0;j < n2;j++)
        cout<<"S";
    for(int k = 1;k <= n3;k++)
        cout<<k;
    cout<<endl;
}
