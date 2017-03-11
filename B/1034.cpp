#include <iostream>
#include <sstream>
#include <cmath>
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
    if(a == b) return b;
    else if(a < b) return gcd(a,b-a);
    else return gcd(a-b,b);
}

long long lcm(long long a,long long b)
{
    return (a*b)/gcd(a,b);
}

string simplification(long long a,long long b)
{
    if(!(a*b)) return "0";
    else if(abs(a) / abs(b))
    {
        if(abs(a) % abs(b))
        {
            if(a*b > 0) return itos(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b));
            else return "(-"+itos(abs(a)/abs(b))+" "+simplification(abs(a)%abs(b),abs(b))+")";
        }
        else
        {
            if(a*b > 0) return itos(abs(a)/abs(b));
            else return "(-"+itos(abs(a)/abs(b))+")";
        }
    }
    else
    {
        long long abgcd = gcd(abs(a),abs(b));
        a /= abgcd;b /= abgcd;
        if(a*b > 0) return itos(abs(a))+"/"+itos(abs(b));
        else return "(-"+itos(abs(a))+"/"+itos(abs(b))+")";
    }
}

long long numerator(string a)
{
    return ston(a);
}

long long denominator(string a)
{
    return ston(a.substr(a.find("/") + 1));
}

string addition(long long a1,long long a2,long long b1,long long b2)
{
    if(!a1) return simplification(b1,b2);
    else if(!b1) return simplification(a1,a2);
    else
    {
        long long common_denominator = lcm(a2,b2);
        a1 *= common_denominator/a2;b1 *= common_denominator/b2;
        long long result_numerator = (a1 + b1) / gcd(abs(a1 + b1),abs(common_denominator));
        long long result_denominator = common_denominator / gcd(abs(a1 + b1),abs(common_denominator));
        return simplification(result_numerator,result_denominator);
    }
}

string subtraction(long long a1,long long a2,long long b1,long long b2)
{
    if(!a1) return simplification(-b1,-b2);
    else if(!b1) return simplification(a1,a2);
    else
    {
        long long common_denominator = lcm(a2,b2);
        a1 *= common_denominator/a2;b1 *= common_denominator/b2;
        long long result_numerator = (a1 - b1) / gcd(abs(a1 - b1),abs(common_denominator));
        long long result_denominator = common_denominator / gcd(abs(a1 - b1),abs(common_denominator));
        return simplification(result_numerator,result_denominator);
    }
}

string multiplication(long long a1,long long a2,long long b1,long long b2)
{
    return simplification(a1*b1,a2*b2);
}

string division(long long a1,long long a2,long long b1,long long b2)
{
    if(!b1) return "Inf";
    else return simplification(a1*b2,a2*b1);
}

int main()
{
    string a,b;
    cin>>a>>b;
    long long a1 = numerator(a);long long a2 = denominator(a);
    long long b1 = numerator(b);long long b2 = denominator(b);
    string as = simplification(a1,a2);string bs = simplification(b1,b2);
    cout<<as<<" + "<<bs<<" = "<<addition(a1,a2,b1,b2)<<endl;
    cout<<as<<" - "<<bs<<" = "<<subtraction(a1,a2,b1,b2)<<endl;
    cout<<as<<" * "<<bs<<" = "<<multiplication(a1,a2,b1,b2)<<endl;
    cout<<as<<" / "<<bs<<" = "<<division(a1,a2,b1,b2)<<endl;
}
