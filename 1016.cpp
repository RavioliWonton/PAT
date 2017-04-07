#include <iostream>
#include <string>
#include <cmath>
using namespace std;

char itoc(int i)
{
    return (char)(i+48);
}

int CalculateP(string a,int da)
{
    int s,p;
    s = p = 0;
    for(int i = 0; i < a.length(); i++)
        if(a[i] == itoc(da)) s++;
    for(; s>0; s--)
        p += pow((double)10,s-1)*da;
    return p;
}

int main()
{
    string a,b;
    int da,db,pa,pb;
    cin>>a>>da>>b>>db;
    pa = CalculateP(a,da);
    pb = CalculateP(b,db);
    cout<<pa+pb<<endl;
}
