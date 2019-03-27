#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int CalculateP(string a,int da)
{
    auto itoc = [&](int i)->char{return i + '0';};
    int s = count(a.begin(),a.end(),itoc(da)),p = 0;
    for(; s>0; s--) p += pow((double)10,s-1)*da;
    return p;
}

int main()
{
    string a,b;
    int da,db;
    cin>>a>>da>>b>>db;
    cout<<CalculateP(a,da)+CalculateP(b,db)<<endl;
}
