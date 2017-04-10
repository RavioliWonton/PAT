#include <iostream>
#include <string>
using namespace std;

void append(string& s,int&& length)
{
    int limit = length - s.size();
    for(int i = 0;i < limit;i++) s.push_back('0');
}

bool judgeplus(string& a,string& b,string& c,int control)
{
    auto atoi = [](char a)-> int {return (a - 48);};
    auto itoa = [](int i)-> char {return (i + 48);};
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

bool judgeminus(string& a,string& b,string& c,int control)
{
    auto atoi = [](char a)-> int {return (a - 48);};
    auto itoa = [](int i)-> char {return (i + 48);};
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
        if(c.front() == '-')
        {
            if(a.front() == '-' && b.front() == '-')
            {
                a.erase(0,1);b.erase(0,1);c.erase(0,1);
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag =  judgeplus(a,b,c,2);
            }
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);c.erase(0,1);
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag = judgeminus(a,b,c,2);
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);c.erase(0,1);
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag = judgeminus(a,b,c,2);
            }
            else flag = true;
        }
        else
        {
            if(a.front() != '-' && b.front() != '-')
            {
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag =  judgeplus(a,b,c,1);
            }
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag = judgeminus(a,b,c,1);
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);
                append(a,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(b,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                append(c,((a.length() >= b.length() ? a : b).length() >= c.length() ? (a.length() >= b.length() ? a : b) : c).size());
                flag = judgeminus(a,b,c,1);
            }
        }
        cout<<"Case #"<<i<<": "<<boolalpha<<flag<<endl;
    }
}
