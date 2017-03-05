#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int caculateSum(int a)
{
    int sum = 0;
    for(;a >= 10;)
    {
        sum += a%10;
        a /= 10;
    }
    return sum+a;
}

int main()
{
    int n;
    cin>>n;
    int (*p) = new int[n];
    for(int i = 0;i < n;i++) cin>>p[i];
    int (*f) = new int[n];int countn = 0;
    for(int i = 0;i < n;i++)
    {
        bool flag = false;
        for(int k = 0;k < countn;k++)
        {
            if(f[k] == caculateSum(p[i]))
            {
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            f[countn] = caculateSum(p[i]);
            countn++;
        }
    }
    delete [] p;
    cout<<countn<<endl;
    sort(f,f+countn,less<int>());
    cout<<f[0];
    for(int i = 1;i < countn;i++) cout<<" "<<f[i];
    cout<<endl;
    delete [] f;
}
