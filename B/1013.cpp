#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    bool (*pb) = new bool[104730];memset(pb,true,sizeof(bool)*104730);
    for(int i = 2;i < sqrt(104730);i++)
    {
        if(pb[i])
        {
            for(int j = i;i*j < 104730;j++)
                pb[i*j] = false;
        }
    }
    int (*pi) = new int[10001];int pj = 1;
    for(int i = 2;i < 104730;i++)
    {
        if(pb[i])
        {
            pi[pj] = i;
            pj++;
        }
    }
    delete [] pb;
    int m,n;
    cin>>m>>n;
    int countn = 0;
    for(int i = m;i <= n;i++)
    {
        countn++;
        if(countn%10 != 0 && i != n)
            cout<<pi[i]<<" ";
        else
            cout<<pi[i]<<endl;
    }
    delete [] pi;
}
