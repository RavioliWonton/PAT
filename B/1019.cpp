#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
const int n = 4;

int *fitofa(int fi)
{
    static int fa[n];
    fa[0] = fi / 1000;
    fa[1] = (fi - fa[0] * 1000) / 100;
    fa[2] = (fi - fa[0] * 1000 - fa[1] * 100) / 10;
    fa[3] = fi - fa[0] * 1000 - fa[1] * 100 - fa[2] * 10;
    return fa;
}

int fatofi(int *fa)
{
    return (fa[0]*1000+fa[1]*100+fa[2]*10+fa[3]);
}

bool NonDecr(int a,int b)
{
    return a <= b;
}

bool NonIncr(int a,int b)
{
    return a >= b;
}

int main()
{
    int ip,iq;
    cin>>ip;iq = ip;
    int (*fip) = new int[n];
    fip = fitofa(ip);
    cout<<setfill('0');
    if(fip[0] == fip[1] && fip[0] == fip[2] && fip[0] == fip[3]) cout<<setw(4)<<ip<<" - "<<setw(4)<<ip<<" = "<<"0000"<<endl;
    else
    {
        for(;(ip - iq) != 6174;)
        {
            sort(fip,fip+n,NonIncr);ip = fatofi(fip);
            sort(fip,fip+n,NonDecr);iq = fatofi(fip);
            cout<<setw(4)<<ip<<" - "<<setw(4)<<iq<<" = "<<setw(4)<<(ip - iq)<<endl;
            fip = fitofa(ip - iq);
        }
    }
    delete [] fip;
}
