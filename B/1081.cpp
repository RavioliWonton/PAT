//那要是我密码是“......”呢？

#include <iostream>
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
        else
        {
            int nc = 0,nn = 0;
            bool flag = true;
            for(char &c : s)
            {
                if(isdigit(c)) nn++;
                else if(isalpha(c)) nc++;
                else if(c != '.')
                {
                    cout<<"Your password is tai luan le.\n";
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                if(!nc) cout<<"Your password needs zi mu.\n";
                else if(!nn) cout<<"Your password needs shu zi.\n";
                else cout<<"Your password is wan mei.\n";
            }
        }
    }
}
