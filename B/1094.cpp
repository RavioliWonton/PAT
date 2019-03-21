#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    int l,k;
    cin>>l>>k;
    string n;
    cin>>n;
    bool flag = false;
    auto judge = [&](int n)->bool
                {
                    if(n < 2) return false;
                    else
                    {
                        for(int i = 2;i < sqrt(n);i++)
                        if(!(n % i)) return false;
                    }
                    return true;
                };
    for(auto it = n.begin();it != n.end() && distance(n.begin(),it) + k <= l;it++)
    {
        string num(it,next(it,k));
        if(judge(stoi(num))) {cout<<num<<endl;flag = true;break;}
    }
    if(!flag) cout<<"404"<<endl;
}
