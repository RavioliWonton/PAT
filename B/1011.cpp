//原来的代码居然能过我也是醉了。
//本算法针对的是无穷大整数，如果你只是想过的话用long long保存输入数据就好啦。

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void append(string& s,int&& length)
{
    int limit = length - s.size();
    for(int i = 0;i < limit;i++) s.insert(0,"0");
}

void handler(string& a,string& b,string& c)
{
    append(a,max({a.size(),b.size(),c.size()}));
    append(b,max({a.size(),b.size(),c.size()}));
    append(c,max({a.size(),b.size(),c.size()}));
}

bool judgeplus(string& a,string& b,string& c,const bool& control)
{
    handler(a,b,c);
    auto atoi = [](char a)-> int {return (a - 48);};
    auto itoa = [](int i)-> char {return (i + 48);};
    string sum(a.size(),0);int carry = 0;
    for(int  i = a.size() - 1;i >= 0;i--)
    {
        sum[i] = itoa(atoi(a[i]) + atoi(b[i]) + carry);
        carry = (atoi(a[i]) + atoi(b[i])) / 10;
    }
    return (control ? (sum > c) : (sum < c));
}

bool judgeminus(string& a,string& b,string& c,const bool& control1,const bool& control2)
{
    handler(a,b,c);
    auto atoi = [](char a)-> int {return (a - 48);};
    auto itoa = [](int i)-> char {return (i + 48);};
    string diff(a.size(),0);const int borrow = 10;
    bool flag = (((control1 && max(a,b) == a) || (!control1 && max(a,b) == b)) ? true : false);
    for(int i = a.size() - 1;i >= 0;i--)
    {
        int difference = atoi(max(a,b).at(i)) - atoi(min(a,b).at(i));
        if(difference < 0)
        {
            difference += borrow;
            if(i)
            {
                int shift = 1;
                for(;max(a,b).at(i - shift) == '0' && shift <= i;) shift++;
                (a > b ? a : b).at(i - shift) = itoa(atoi(max(a,b).at(i - shift)) - 1);
                for(int j = i - shift + 1;j < i;j++) (a > b ? a : b).at(j) = '9';
            }
        }
        diff[i] = itoa(difference % 10);
    }
    if(flag && control2) return (flag ? (diff > c) : (diff < c));
    else return (flag ? true : false);
}

int main()
{
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        string a,b,c;
        cin>>a>>b>>c;
        bool flag = false;
        if(c.front() == '-')
        {
            c.erase(0,1);
            if(a.front() == '-' && b.front() == '-')
            {
                a.erase(0,1);b.erase(0,1);c.erase(0,1);
                flag =  judgeplus(a,b,c,false);
            }
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);
                flag = judgeminus(a,b,c,false,false);
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);
                flag = judgeminus(a,b,c,true,false);
            }
            else flag = true;
        }
        else
        {
            if(a.front() != '-' && b.front() != '-')  flag =  judgeplus(a,b,c,true);
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);
                flag = judgeminus(a,b,c,false,true);
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);
                flag = judgeminus(a,b,c,true,true);
            }
        }
        cout<<"Case #"<<i + 1<<": "<<boolalpha<<flag<<endl;
    }
}
