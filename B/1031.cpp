#include <iostream>
#include <string>
using namespace std;

int stoi(char c) {return (int)(c - 48);}

int calculateVerification(string a)
{
    int sum = 0;int p[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};int m[] = {1,0,10,9,8,7,6,5,4,3,2};
    for(int i = 0;i < a.length() - 1;i++)
    {
        if(stoi(a[i]) >= 0 && stoi(a[i]) <= 9)
            sum += p[i]*stoi(a[i]);
        else return -1;
    }
    sum %= 11;
    return m[sum];
}

int main()
{
    int n;
    cin>>n;
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        string a;
        cin>>a;
        if(calculateVerification(a) == 10)
        {if(calculateVerification(a) == -1 || a[a.length() - 1] != 'X') {cout<<a<<endl;flag = false;}}
        else if((calculateVerification(a) != stoi(a[a.length() - 1])) || calculateVerification(a) == -1) {cout<<a<<endl;flag = false;}
    }
    if(flag) cout<<"All passed"<<endl;
}
