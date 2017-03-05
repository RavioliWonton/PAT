//从未见过如此坑人之题！

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
	double r1,p1,r2,p2;
	cin>>r1>>p1>>r2>>p2;
	cout<<setiosflags(ios::fixed)<<setprecision(2);
	bool flag = true;
	if(abs(r1*r2*cos(p1+p2)) >= 0.01 && r1*r2*cos(p1+p2) != 0) cout<<r1*r2*cos(p1+p2);
	else {cout<<"0.00";flag = false;}
    if(abs(r1*r2*sin(p1+p2)) >= 0.01 && r1*r2*sin(p1+p2) < 0) cout<<"-"<<abs(r1*r2*sin(p1+p2))<<"i"<<endl;
    else if(abs(r1*r2*sin(p1+p2)) >= 0.01 && r1*r2*sin(p1+p2) > 0) cout<<"+"<<r1*r2*sin(p1+p2)<<"i"<<endl;
    else if(flag) cout<<"+0.00i"<<endl;
    else cout<<endl;
}
