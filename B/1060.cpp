#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int (*p) = new int[n+1];int a = 0;
    for(int i = 1;i < n+1;i++) cin>>p[i];
    sort(p+1,p+n+1,greater<int>());
    for(int j = 1;j < n+1;j++)
        if(p[j] > j) a++;
    cout<<a<<endl;
    delete [] p;
}
