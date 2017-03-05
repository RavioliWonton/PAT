#include <iostream>
#include <string>
using namespace std;

int countPATest(string s,int c)
{
    int r = 0;
    switch(c)
    {
        case 1:for(int i = 0;i < s.length();i++){if(s[i] == 'P') r++;}break;
        case 2:for(int i = 0;i < s.length();i++){if(s[i] == 'A') r++;}break;
        case 3:for(int i = 0;i < s.length();i++){if(s[i] == 'T') r++;}break;
        case 4:for(int i = 0;i < s.length();i++){if(s[i] == 'e') r++;}break;
        case 5:for(int i = 0;i < s.length();i++){if(s[i] == 's') r++;}break;
        case 6:for(int i = 0;i < s.length();i++){if(s[i] == 't') r++;}break;
    }
    return r;
}

int main()
{
    string s;
    cin>>s;
    int (*a) = new int[6];
    for(int i = 0;i < 6;i++) a[i] = countPATest(s,i+1);
    for(;a[0] || a[1] || a[2] || a[3] || a[4] || a[5];)
    {
        if(a[0]) {cout<<"P";a[0]--;}
        if(a[1]) {cout<<"A";a[1]--;}
        if(a[2]) {cout<<"T";a[2]--;}
        if(a[3]) {cout<<"e";a[3]--;}
        if(a[4]) {cout<<"s";a[4]--;}
        if(a[5]) {cout<<"t";a[5]--;}
    }
    cout<<endl;
    delete [] a;
}
