#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    int ip;
    cin>>ip;
    string fip = to_string(ip);
    fip.resize(4,'0');
    cout<<setfill('0');
    if(count(fip.begin(),fip.end(),fip.front()) != 4)
    {
        int iq = ip;
        for(;(ip - iq) != 6174;)
        {
            sort(fip.begin(),fip.end(),greater_equal<int>());
            ip = stoi(fip);
            sort(fip.begin(),fip.end(),less_equal<int>());
            iq = stoi(fip);
            cout<<setw(4)<<ip<<" - "<<setw(4)<<iq<<" = "<<setw(4)<<(ip - iq)<<"\n";
            fip = to_string(ip - iq);
            fip.resize(4,'0');
        }
    }
    else cout<<fip<<" - "<<fip<<" = "<<"0000"<<endl;
}
