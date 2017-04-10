#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    bool (*a) = new bool[n+1];
    memset(a,true,sizeof(bool)*(n+1));
    for (int i = 2; i <= sqrt(n); i++)
        if (a[i]) for(int j = i; j*i <= n; j++) a[j*i] = false;
    int first = 0;int last = 0;int countn = 0;
    for(int i = 2; i < n + 1; i++)
    {
        if(a[i])
        {
            if(!first) first = i;
            else
            {
                if(last) first = last;
                last = i;
                if(last - first == 2) countn++;
            }
        }
    }
    cout<<countn<<endl;
    delete [] a;
}
