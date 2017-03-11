//题目保证正确的输出中没有超过整型范围的整数，可没说计算过程中没有.........

#include <iostream>
#include <sstream>
#include <cstdlib>
using namespace std;

string itos(long long i)
{
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    ss.clear();
    ss.str("");
    return s;
}

long long ston(string s)
{
    long long i;
    stringstream ss(s);
    ss >> i;
    ss.clear();
    ss.str("");
    return i;
}

long long gcd(long long a,long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

string simplification(long long a,long long b)
{
    if(!(a*b)) return "0";
    else if(abs(a) / abs(b))
    {
        if(abs(a) % abs(b)) return (a*b > 0 ? itos(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b)) : "(-"+itos(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b))+")");
        else return (a*b > 0 ? itos(abs(a)/abs(b)) : "(-"+itos(abs(a)/abs(b))+")");
    }
    else
    {
        long long abgcd = gcd(abs(a),abs(b));
        a /= abgcd;b /= abgcd;
        return (a*b > 0 ? itos(abs(a))+"/"+itos(abs(b)) : "(-"+itos(abs(a))+"/"+itos(abs(b))+")");
    }
}

int main()
{
	string a,b;
	cin>>a>>b;
    long long a1 = ston(a);long long a2 = ston(a.substr(a.find("/") + 1));
    long long b1 = ston(b);long long b2 = ston(b.substr(b.find("/") + 1));
    string as = simplification(a1,a2);string bs = simplification(b1,b2);
    cout<<as<<" + "<<bs<<" = "<<simplification(a1*b2+a2*b1,a2*b2)<<endl;
    cout<<as<<" - "<<bs<<" = "<<simplification(a1*b2-a2*b1,a2*b2)<<endl;
    cout<<as<<" * "<<bs<<" = "<<simplification(a1*b1,a2*b2)<<endl;
    cout<<as<<" / "<<bs<<" = "<<(!b1 ? "Inf" : simplification(a1*b2,a2*b1))<<endl;
}
