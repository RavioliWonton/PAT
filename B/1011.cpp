#include <iostream>
#include <string>
using namespace std;

int atoi(char a)
{
    return (int)(a - 48);
}

char itoa(int i)
{
    return (char)(i + 48);
}

string append(string s,string maxs)
{
    string a;
    for(int i = 0;i < maxs.length() - s.length();i++)
        a += "0";
    a += s;
    return a;
}

bool judgeplus(string a,string b,string c,int control)
{
    string sum(a.length(),0);int carry = 0;
    for(int  i = a.length() - 1;i >= 0;i--)
    {
        sum[i] = itoa(atoi(a[i]) + atoi(b[i]) + carry);
        carry = (atoi(a[i]) + atoi(b[i])) / 10;
    }
    switch(control)
    {
        case 1:{if(sum > c) return true;else return false;}
        case 2:{if(sum < c) return true;else return false;}
    }
}

bool judgeminus(string a,string b,string c,int control)
{
    string maxs = (a > b ? a : b);string mins = (a < b ? a : b);
    string diff(a.length(),0);const int borrow = 10;
    for(int i = 0;i < a.length();i++)
        diff[i] = itoa((atoi(maxs[i]) - atoi(mins[i]) + borrow) % 10);
    switch(control)
    {
        case 1:{if(diff > c) return true;else return false;}
        case 2:{if(diff < c) return true;else return false;}
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        string a,b,c;bool flag = false;
        cin>>a>>b>>c;
        if(c[0] == '-')
        {
            if(a[0] == '-' && b[0] == '-')
            {
                a = a.substr(1,string::npos);
                b = b.substr(1,string::npos);
                c = c.substr(1,string::npos);
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag =  judgeplus(a,b,c,2);
            }
            else if(a[0] == '-' && b[0] != '-')
            {
                a = a.substr(1,string::npos);
                c = c.substr(1,string::npos);
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag = judgeminus(a,b,c,2);
            }
            else if(a[0] != '-' && b[0] == '-')
            {
                b = b.substr(1,string::npos);
                c = c.substr(1,string::npos);
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag = judgeminus(a,b,c,2);
            }
            else
                flag = true;
        }
        else
        {
            if(a[0] != '-' && b[0] != '-')
            {
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag =  judgeplus(a,b,c,1);
            }
            else if(a[0] == '-' && b[0] != '-')
            {
                a = a.substr(1,string::npos);
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag = judgeminus(a,b,c,1);
            }
            else if(a[0] != '-' && b[0] == '-')
            {
                b = b.substr(1,string::npos);
                a = append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                b = append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                c = append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c));
                flag = judgeminus(a,b,c,1);
            }
        }
        if(flag) cout<<"Case #"<<i<<": true"<<endl;
        else cout<<"Case #"<<i<<": false"<<endl;
    }
}
