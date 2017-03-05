#include <iostream>
#include <cmath>
using namespace std;
int CountRequiredPrime(int n)
{
        bool (*a) = new bool[n+1];
        for (int i = 2; i <= n; i++)  a[i] = true;
        int (*p) = new int[n];
        for (int i = 0; i < n;i++) p[i] = '\0';
        int countn = 0;
        for (int i = 2; i <= sqrt(n); i++)
            if (a[i])
                for (int j = i; j*i <= n; j++) a[j*i] = false;
        int b = 0;
        for (int k = 2; k <= n; k++)
            if (a[k]) {p[b] = k;b++;}
        for(int l = 0;p[l+1] != '\0';l++)
            if(p[l+1] - p[l] == 2) countn++;
        return countn;
}

int main()
{
    int n;
    cin>>n;
    cout<<CountRequiredPrime(n)<<endl;
}
