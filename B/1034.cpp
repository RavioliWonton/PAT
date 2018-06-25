//脑残题目，非要开unsigned long long才肯过我的，十足脑残。

#include <iostream>
#include <string>
#include <functional>
using namespace std;

string simplification(unsigned long long&& a,unsigned long long&& b,bool&& flag)
{
    if(!(a&&b)) return "0";
    else if(a / b)
    {
        if(a % b) return move(flag ? to_string(a/b)+" "+simplification(a%b,move(b),true) : "(-"+to_string(a/b)+" "+simplification(a%b,move(b),true)+")");
        else return move(flag ? to_string(a/b) : "(-"+to_string(a/b)+")");
    }
    else
    {
        function<unsigned long long(const unsigned long long, const unsigned long long)> gcd = [&](auto a, auto b)->long long{return b == 0 ? a : gcd(b, a % b);};
        return move(flag ? to_string(a / gcd(a,b))+"/"+to_string(b / gcd(a,b)) : "(-"+to_string(a / gcd(a,b))+"/"+to_string(b / gcd(a,b))+")");
    }
}

int main()
{
	string a,b;
	cin>>a>>b;
    auto a1 = stoll(a), a2 = stoll(a.substr(a.find("/") + 1)), b1 = stoll(b), b2 = stoll(b.substr(b.find("/") + 1));
    auto as = simplification(abs(a1),a2,a1*a2 > 0),bs = simplification(abs(b1),b2,b1*b2 > 0);
    cout<<as<<" + "<<bs<<" = "<<simplification(abs(a1*b2+a2*b1),a2*b2,(a1*b2+a2*b1)*a2*b2 > 0)<<endl;
    cout<<as<<" - "<<bs<<" = "<<simplification(abs(a1*b2-a2*b1),a2*b2,(a1*b2-a2*b1)*a2*b2 > 0)<<endl;
    cout<<as<<" * "<<bs<<" = "<<simplification(abs(a1*b1),a2*b2,a1*b1 > 0)<<endl;
    cout<<as<<" / "<<bs<<" = "<<(!b1 ? "Inf" : simplification(abs(a1*b2),abs(a2*b1),a1*b1 > 0))<<endl;
}
