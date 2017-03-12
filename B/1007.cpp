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
        if (a[i]) for (int j = i; j*i <= n; j++) a[j*i] = false;
    int (*p) = new int[n];int countp = 0;
    for (int k = 2; k <= n; k++)
        if (a[k]) {p[countp] = k;countp++;}
    int countn = 0;
    for(int l = 0; l < countp; l++)
        if(p[l+1] - p[l] == 2) countn++;
    cout<<countn<<endl;
    delete [] a;delete [] p;
}
