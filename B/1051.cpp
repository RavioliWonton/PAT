//用标准库的complex重写了一遍.......
//当然，我还是要说，从未见过如此坑人之题！

#include <iostream>
#include <iomanip>
#include <complex>
using namespace std;

ostream& operator<<(ostream& out,const complex<double>& rhs)
{
    out.setf(ios::fixed);
    out.precision(2);
    if(abs(rhs.real()) < 0.01 || rhs.real() == 0.0) out <<"0.00"<<(rhs.imag() >= 0 || abs(rhs.imag()) < 0.01 ? "+" : "")<<(abs(rhs.imag()) < 0.01 || rhs.imag() == 0.0 ? 0.0 : rhs.imag())<<"i";
    else out << rhs.real()<<(rhs.imag() >= 0 || abs(rhs.imag()) < 0.01 ? "+" : "")<< (abs(rhs.imag()) < 0.01 || rhs.imag() == 0.0 ? 0.0 : rhs.imag())<<"i";
    return out;
}

int main()
{
    double r1,p1,r2,p2;
    cin>>r1>>p1>>r2>>p2;
    complex<double> z = polar(r1,p1)*polar(r2,p2);
    cout<<z<<endl;
}

/*int main()
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
}*/
