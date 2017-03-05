#define ERROR -1
#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int atoi(char c) {return (int)(c - 48);}

string itos(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

int stoi(string s)
{
    int i;
    stringstream ss(s);
    ss >> i;
    return i;
}

string simplification(int a1,int b1)
{
    if(a1*b1 == 0) return "0";
    else if(abs(a1)/abs(b1) != 0)
    {
        if(abs(a1)%abs(b1) == 0 && a1*b1 > 0)
            return itos(abs(a1)/abs(b1));
        else if(abs(a1)%abs(b1) == 0 && a1*b1 < 0)
            return "-"+itos(abs(a1)/abs(b1));
        else if(abs(a1)%abs(b1) != 0 && a1*b1 > 0)
            return itos(abs(a1)/abs(b1))+" "+itos(a1 - a1%b1)+"/"+itos(b1);
        else if(abs(a1)/abs(b1) != 0 && a1*b1 < 0)
            return " "+itos(abs(a1)/abs(b1))+" "+itos(a1 - a1%b1)+"/"+itos(b1);
    }
    else if(abs(a1)/abs(b1) == 0 && a1*b1 < 0)
        return "-"+itos(abs(a1))+"/"+itos(abs(b1));
    else return itos(abs(a1))+"/"+itos(abs(b1));
}

int numerator(string a)
{
    if(a[0] == '-') return -atoi(a[1]);
    else return atoi(a[0]);
}

int denominator(string a)
{
    return atoi(a[a.find("/") + 1]);
}

string add(int a1,int b1,int a2,int b2)
{

}

int main()
{
	string a,b;
	cin>>a>>b;
    int a1 = numerator(a);int a2 = denominator(a);
    int b1 = numerator(b);int b2 = denominator(b);
    string ap = simplification(a1,a2);string bp = simplification(b1,b2);
}
