//那要是我密码是“......”呢？

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin>>s;
        if(s.size() < 6) cout<<"Your password is tai duan le.\n";
        else if(find_if(s.begin(),s.end(),[&](char a)->bool{return !isalnum(a) && (a != '.');}) != s.end()) cout<<"Your password is tai luan le.\n";
        else if(!count_if(s.begin(),s.end(),::isdigit)) cout<<"Your password needs shu zi.\n";
        else if(!count_if(s.begin(),s.end(),::isalpha)) cout<<"Your password needs zi mu.\n";
        else cout<<"Your password is wan mei.\n";
    }
}
