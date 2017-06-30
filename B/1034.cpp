//题目保证正确的输出中没有超过整型范围的整数，可没说计算过程中没有.........

#include <iostream>
#include <string>
using namespace std;

long long gcd(long long a,long long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

string simplification(long long a,long long b)
{
    if(!(a&&b)) return "0";
    else if(abs(a) / abs(b))
    {
        if(abs(a) % abs(b)) return (a*b > 0 ? to_string(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b)) : "(-"+to_string(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b))+")");
        else return (a*b > 0 ? to_string(abs(a)/abs(b)) : "(-"+to_string(abs(a)/abs(b))+")");
    }
    else
    {
        long long abgcd = gcd(abs(a),abs(b));
        a /= abgcd;b /= abgcd;
        return (a*b > 0 ? to_string(abs(a))+"/"+to_string(abs(b)) : "(-"+to_string(abs(a))+"/"+to_string(abs(b))+")");
    }
}

int main()
{
	string a,b;
	cin>>a>>b;
    long long a1 = stoll(a);long long a2 = stoll(a.substr(a.find("/") + 1));
    long long b1 = stoll(b);long long b2 = stoll(b.substr(b.find("/") + 1));
    string as = simplification(a1,a2);string bs = simplification(b1,b2);
    cout<<as<<" + "<<bs<<" = "<<simplification(a1*b2+a2*b1,a2*b2)<<endl;
    cout<<as<<" - "<<bs<<" = "<<simplification(a1*b2-a2*b1,a2*b2)<<endl;
    cout<<as<<" * "<<bs<<" = "<<simplification(a1*b1,a2*b2)<<endl;
    cout<<as<<" / "<<bs<<" = "<<(!b1 ? "Inf" : simplification(a1*b2,a2*b1))<<endl;
}
