#include <iostream>
#include <sstream>
#include <deque>
#include <list>
#include <algorithm>
using namespace std;

void inputScalenumber(deque<int>& l)
{
    string s;
    cin>>s;
    stringstream ss(s);
    char temp;
    auto f = [&](char c)->int{return (int)(c - '0');};
    for(; ss>>temp;) l.push_back(f(temp) ? f(temp) : 10);
    ss.clear();
    ss.str("");
}

void inputOperand(deque<int>& l)
{
    string s;
    cin>>s;
    stringstream ss(s);
    char temp;
    auto f = [&](char c)->int{return (int)(c - '0');};
    bool flag = true;
    for(; ss>>temp;)
    {
        if(flag && f(temp))
        {
            l.push_back(f(temp));
            flag = false;
        }
        else if(!flag) l.push_back(f(temp));
    }
    ss.clear();
    ss.str("");
}

int main()
{
    deque<int> n,n1,n2;
    list<int> result;
    inputScalenumber(n);
    inputOperand(n1);
    inputOperand(n2);
    int maxsize = max(n1.size(),n2.size());
    for(;maxsize - n1.size() > 0;) n1.push_front(0);
    for(;maxsize - n2.size() > 0;) n2.push_front(0);
    int carry = 0;
    for(int i = maxsize - 1;i >= 0;i--)
    {
        int sum = n1[i] + n2[i] + carry;
        cout<<sum<<endl;
        carry = sum / n[i];
        result.push_front(sum % n[i]);
    }
    if(!carry) result.push_front(carry);
    for_each(result.begin(),result.end(),[&](int i)->void{cout<<i;});
    cout<<endl;
}
