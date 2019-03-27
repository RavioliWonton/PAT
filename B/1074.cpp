#include <iostream>
#include <sstream>
#include <list>
#include <algorithm>
using namespace std;

void inputScalenumber(list<int>& l)
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

void inputOperand(list<int>& l)
{
    string s;
    cin>>s;
    stringstream ss(s);
    char temp;
    auto f = [&](char c)->int{return (int)(c - '0');};
    for(; ss>>temp;) l.push_back(f(temp));
    for(;!l.front() && l.size() > 1;) l.pop_front();
    ss.clear();
    ss.str("");
}

int main()
{
    list<int> n,n1,n2,result;
    inputScalenumber(n);
    inputOperand(n1);
    inputOperand(n2);
    int maxsize = max(n1.size(),n2.size()),carry = 0;
    for(;maxsize - n1.size() > 0;) n1.push_front(0);
    for(;maxsize - n2.size() > 0;) n2.push_front(0);
    for(int i = 0;i < maxsize;i++)
    {
        int sum = *(next(n1.rbegin(),i)) + *(next(n2.rbegin(),i)) + carry;
        carry = sum / *(next(n.rbegin(),i));
        result.push_front(sum % *(next(n.rbegin(),i)));
    }
    if(carry) result.push_front(carry);
    for_each(result.begin(),result.end(),[&](int i)->void{cout<<i;});
    cout<<endl;
}
