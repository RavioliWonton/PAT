#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int judge(char c)
{
    if(c >= '0' && c<= '9') return c-48;
    else return -1;
}

int main()
{
	string a;
	cin>>a;
    int (*p) = new int[10];memset(p,0,sizeof(int)*10);
    for(int i = 0;i < a.length();i++)
        if(judge(a[i]) != -1)
            p[judge(a[i])]++;
    for(int i = 0;i < 10;i++)
        if(p[i])
            cout<<i<<":"<<p[i]<<endl;
    delete [] p;
}
