#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

string itos(int i)
{
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    ss.clear();
    ss.str("");
    return s;
}

int stoi(string s)
{
    int i;
    stringstream ss(s);
    ss >> i;
    ss.clear();
    ss.str("");
    return i;
}

int gcd(int a,int b)
{
    if(a == b) return b;
    else if(a < b) return gcd(a,b-a);
    else return gcd(a-b,b);
}

int lcm(int a,int b)
{
    return (a*b)/gcd(a,b);
}

string simplification(int a1,int b1)
{
    if(a1*b1 == 0) return "0";
    else if(abs(a1)/abs(b1) != 0)
    {
        if(abs(a1)%abs(b1) == 0 && a1*b1 > 0)
            return itos(abs(a1)/abs(b1));
        else if(abs(a1)%abs(b1) == 0 && a1*b1 < 0)
            return "(-"+itos(abs(a1)/abs(b1))+")";
        else if(abs(a1)%abs(b1) != 0 && a1*b1 > 0)
            return itos(abs(a1)/abs(b1))+" "+itos(a1 - a1%b1)+"/"+itos(b1);
        else if(abs(a1)/abs(b1) != 0 && a1*b1 < 0)
            return "(-"+itos(abs(a1)/abs(b1))+" "+itos(a1 - a1%b1)+"/"+itos(b1)+")";
    }
    else if(abs(a1)/abs(b1) == 0 && a1*b1 < 0)
        return "(-"+itos(abs(a1))+"/"+itos(abs(b1))+")";
    else return itos(abs(a1))+"/"+itos(abs(b1));
}

int numerator(string a)
{
    return stoi(a);
}

int denominator(string a)
{
    return stoi(a.substr(a.find("/") + 1));
}

string addition(int a1,int a2,int b1,int b2)
{
    if(!a1) return simplification(b1,b2);
    else if(!b1) return simplification(a1,a2);
    else
    {
        int common_denominator = lcm(a2,b2);
        a1 *= common_denominator/a2;b1 *= common_denominator/b2;
        int result_numerator = (a1 + b1) / gcd(a1 + b1,common_denominator);
        int result_denominator = common_denominator / gcd(a1 + b1,common_denominator);
        return simplification(result_numerator,result_denominator);
    }
}

string subtraction(int a1,int a2,int b1,int b2)
{
    if(!a1) return simplification(-b1,-b2);
    else if(!b1) return simplification(a1,a2);
    else
    {
        int common_denominator = lcm(a2,b2);
        a1 *= common_denominator/a2;b1 *= common_denominator/b2;
        int result_numerator = (a1 - b1) / gcd(a1 - b1,common_denominator);
        int result_denominator = common_denominator / gcd(a1 - b1,common_denominator);
        return simplification(result_numerator,result_denominator);
    }
}

string multiplication(int a1,int a2,int b1,int b2)
{
    return simplification(a1*b1,a2*b2);
}

string division(int a1,int a2,int b1,int b2)
{
    if(!b1) return "Inf";
    else return simplification(a1*b2,a2*b1);
}

int main()
{
	string a,b;
	cin>>a>>b;
    int a1 = numerator(a);int a2 = denominator(a);
    int b1 = numerator(b);int b2 = denominator(b);
    string as = simplification(a1,a2);string bs = simplification(b1,b2);
    cout<<as<<" + "<<bs<<" = "<<addition(a1,a2,b1,b2)<<endl;
    cout<<as<<" - "<<bs<<" = "<<subtraction(a1,a2,b1,b2)<<endl;
    cout<<as<<" * "<<bs<<" = "<<multiplication(a1,a2,b1,b2)<<endl;
    cout<<as<<" / "<<bs<<" = "<<division(a1,a2,b1,b2)<<endl;
}
