#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
using namespace std;

void printDouble(bool flag,double base,int index,int inputprecision,int realprecision)
{
    cout.setf(ios::fixed);cout.fill('0');
    if(flag)
    {
        if(realprecision - index > 0 && base - (int)base != 0) cout<<setprecision(realprecision-index)<<base*pow(10,index)<<endl;
        else cout<<setprecision(0)<<base*pow(10,index)<<endl;
    }
    else cout<<setprecision(inputprecision+index)<<base*pow(10,-index)<<endl;
}

int getRealprecision(double base)
{
    stringstream ss;
    ss << base;
    string s;
    ss >> s;
    ss.clear();
    ss.str("");
    return s.length() - s.find(".") - 1;
}

int main()
{
	string a;
	cin>>a;
	bool flag1 = true;
	if(a[0] == '-') flag1 = false;
    stringstream ss;
    ss << a.substr(1,a.find('E')-1);
    double base;
    ss >> base;
    bool flag2 = true;
    if(a[a.find('E')+1] == '-') flag2 = false;
    ss.clear();
    ss.str("");
    ss << a.substr(a.find('E')+2,a.length()-a.find('E')-2);
    int index;
    ss >> index;
    if(flag1) printDouble(flag2,base,index,a.find('E')-a.find('.')-1,getRealprecision(base));
    else {cout<<"-";printDouble(flag2,base,index,a.find('E')-a.find('.')-1,getRealprecision(base));}
}
