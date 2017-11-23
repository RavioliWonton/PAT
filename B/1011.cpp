//原来的代码居然能过我也是醉了。
//本算法针对的是无穷大整数，如果你只是想过的话用long long保存输入数据就好啦。

#include <iostream>
#include <string>
#include <limits>
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
    auto atoi = [](char a)-> int {return (a - '0');};
    auto itoa = [](int i)-> char {return (i + '0');};
    string sum(a.size(),0);int carry = 0;
    for(int  i = a.size() - 1;i >= 0;i--)
    {
        int psum = atoi(a[i]) + atoi(b[i]) + carry;
        sum[i] = itoa(psum % 10);
        carry = psum / 10;
    }
    if(carry) sum.insert(0,to_string(carry));
    return (control ? (sum > c) : (sum < c));
}

bool judgeminus(string& a,string& b,string& c,const bool& control)
{
    auto atoi = [](char a)-> int {return (a - '0');};
    auto itoa = [](int i)-> char {return (i + '0');};
    string diff(a.size(),0);
    for(int i = a.size() - 1;i >= 0;i--)
    {
            int difference = atoi(a[i]) - atoi(b[i]);
	        if(difference < 0)
	        {
                int shift = 1;
                for(;a[i - shift] == '0' && shift <= i;) shift++;
                a[i - shift] = itoa(atoi(a[i - shift]) - 1);
                for(int j = i - shift + 1;j < i;j++) a[j] = '9';
                difference += 10;
	        }
	        diff[i] = itoa(difference % 10);
    }
    return (control ? (diff > c) : (diff < c));
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
                a.erase(0,1);b.erase(0,1);
                flag =  judgeplus(a,b,c,false);
            }
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);
                handler(a,b,c);
                flag = (max(a,b) == a ? judgeminus(a,b,c,false) : true);
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);
                handler(a,b,c);
                flag = (max(a,b) == a ? true : judgeminus(b,a,c,false));
            }
            else flag = true;
        }
        else
        {
            if(a.front() != '-' && b.front() != '-') flag =  judgeplus(a,b,c,true);
            else if(a.front() == '-' && b.front() != '-')
            {
                a.erase(0,1);
                handler(a,b,c);
                flag = (max(a,b) == a ? false : judgeminus(b,a,c,true));
            }
            else if(a.front() != '-' && b.front() == '-')
            {
                b.erase(0,1);
                handler(a,b,c);
                flag = (max(a,b) == a ? judgeminus(a,b,c,true) : false);
            }
        }
        cout<<"Case #"<<i + 1<<": "<<boolalpha<<flag<<endl;
    }
}
