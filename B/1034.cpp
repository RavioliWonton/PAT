//脑残题目，非要开unsigned long long才肯过我的，十足脑残。

#include <iostream>
#include <string>
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
        auto gcd = [&](auto a, auto b, auto&& self)->unsigned long long{return b == 0 ? a : self(b, a % b, self);};
        return move(flag ? to_string(a / gcd(a,b,gcd))+"/"+to_string(b / gcd(a,b,gcd)) : "(-"+to_string(a / gcd(a,b,gcd))+"/"+to_string(b / gcd(a,b,gcd))+")");
    }
}

int main()
{
	string a,b;
	cin>>a>>b;
    cout<<simplification(abs(stoll(a)),stoll(a.substr(a.find("/") + 1)),stoll(a)*stoll(a.substr(a.find("/") + 1)) > 0)<<" + "<<simplification(abs(stoll(b)),stoll(b.substr(b.find("/") + 1)),stoll(b)*stoll(b.substr(b.find("/") + 1)) > 0)<<" = "<<simplification(abs(stoll(a)*stoll(b.substr(b.find("/") + 1))+stoll(a.substr(a.find("/") + 1))*stoll(b)),stoll(a.substr(a.find("/") + 1))*stoll(b.substr(b.find("/") + 1)),(stoll(a)*stoll(b.substr(b.find("/") + 1))+stoll(a.substr(a.find("/") + 1))*stoll(b))*stoll(a.substr(a.find("/") + 1))*stoll(b.substr(b.find("/") + 1)) > 0)<<endl;
    cout<<simplification(abs(stoll(a)),stoll(a.substr(a.find("/") + 1)),stoll(a)*stoll(a.substr(a.find("/") + 1)) > 0)<<" - "<<simplification(abs(stoll(b)),stoll(b.substr(b.find("/") + 1)),stoll(b)*stoll(b.substr(b.find("/") + 1)) > 0)<<" = "<<simplification(abs(stoll(a)*stoll(b.substr(b.find("/") + 1))-stoll(a.substr(a.find("/") + 1))*stoll(b)),stoll(a.substr(a.find("/") + 1))*stoll(b.substr(b.find("/") + 1)),(stoll(a)*stoll(b.substr(b.find("/") + 1))-stoll(a.substr(a.find("/") + 1))*stoll(b))*stoll(a.substr(a.find("/") + 1))*stoll(b.substr(b.find("/") + 1)) > 0)<<endl;
    cout<<simplification(abs(stoll(a)),stoll(a.substr(a.find("/") + 1)),stoll(a)*stoll(a.substr(a.find("/") + 1)) > 0)<<" * "<<simplification(abs(stoll(b)),stoll(b.substr(b.find("/") + 1)),stoll(b)*stoll(b.substr(b.find("/") + 1)) > 0)<<" = "<<simplification(abs(stoll(a)*stoll(b)),stoll(a.substr(a.find("/") + 1))*stoll(b.substr(b.find("/") + 1)),stoll(a)*stoll(b) > 0)<<endl;
    cout<<simplification(abs(stoll(a)),stoll(a.substr(a.find("/") + 1)),stoll(a)*stoll(a.substr(a.find("/") + 1)) > 0)<<" / "<<simplification(abs(stoll(b)),stoll(b.substr(b.find("/") + 1)),stoll(b)*stoll(b.substr(b.find("/") + 1)) > 0)<<" = "<<(!stoll(b) ? "Inf" : simplification(abs(stoll(a)*stoll(b.substr(b.find("/") + 1))),abs(stoll(a.substr(a.find("/") + 1))*stoll(b)),stoll(a)*stoll(b) > 0))<<endl;
}
