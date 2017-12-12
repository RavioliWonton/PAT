//看了一波网上的答案，黑人问号？？？
//明天再来改。

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

auto ntoi = [&](char a)->int{return isdigit(a) ? (a - '0') : (a - 'a' + 10);};
auto iton = [&](int i)->char{return i > 10 ? i - 10 + 'a' : i + '0';};

int todeci(const string& s,const int& radix)
{
    int result = 0;
    for(auto it = s.rbegin();it != s.rend();it++) result += ntoi(*it)*pow(radix,it - s.rbegin());
    return result;
}

string tostr(const int& n,const int& radix)
{
    int num = n;
    string result;
    for(;num > radix;)
    {
        result.insert(0,1,iton(num % radix));
        num /= radix;
    }
    result.insert(0,1,iton(num));
    return result;
}

int main()
{
	string n1,n2;
	int tag,radix;
	cin>>n1>>n2>>tag>>radix;
	if(tag == 2) swap(n1,n2);
    int in1 = todeci(n1,radix);
    bool flag = false;
    for(int maxnum = ntoi(*max_element(n2.begin(),n2.end())) + 1;maxnum < 36;maxnum++)
    {
        if(tostr(in1,maxnum) == n2)
        {
            flag = true;
            cout<<maxnum<<endl;
            break;
        }
    }
    if(!flag) cout<<"Impossible"<<endl;
}
