//本题大傻逼！
//第一点——也是最重要的一点——我TM怎么知道第几对相同字符是不是在相同的位置！你又没有明确说明！
//第二点，“第2对相同的字符是'E'”，我TM怎么知道是大写字符还是小写字符！对你后面说了大写字母A-N表示，我TM以为要toupper()一下！
//综上所述，本题就是傻逼，大傻逼！

#include <iostream>
#include <string>
using namespace std;

bool Judge(char a,int i)
{
    switch(i)
    {
        case 1:{if(a >= 'A' && a <= 'G'){return true;}else return false;}break;
        case 2:{if((a >= 'A' && a <= 'N') || (a >= '0' && a <= '9')){return true;}else return false;}break;
        case 3:{if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')){return true;}else return false;}break;
    }
}

void printDays(char c)
{
    switch(c)
    {
        case 'A':cout<<"MON ";break;
        case 'B':cout<<"TUE ";break;
        case 'C':cout<<"WED ";break;
        case 'D':cout<<"THU ";break;
        case 'E':cout<<"FRI ";break;
        case 'F':cout<<"SAT ";break;
        case 'G':cout<<"SUN ";break;
    }
}

void printHour(char c)
{
    if(c >= '0' && c <= '9') cout<<"0"<<c<<":";
    else if(c >= 'A' && c <= 'N') cout<<(int)(c - 'A' + 10)<<":";
}

void JudgeFirst(string a,string b)
{
    int flag;
    for(int i = 0;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],1) && Judge(b[i],1)))
        {
            printDays(a[i]);
            flag = i;
            break;
        }
    }
    for(int i = flag + 1;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],2) && Judge(b[i],2)))
        {
            printHour(a[i]);
            break;
        }
    }
}

void JudgeSecond(string a,string b)
{
    for(int i = 0;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],3) && Judge(b[i],3)))
        {
            cout<<i/10<<i%10<<endl;
            break;
        }
    }
}

int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    JudgeFirst(a,b);
    JudgeSecond(c,d);
}
