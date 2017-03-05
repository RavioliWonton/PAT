//本题傻逼之处：1.一行输完符号之后就不要再输出空格了，否则格式错。
//2.不管剩余多少，即使是0也要输出，否则第二个判断点错。
//十足傻逼！

#include <iostream>
using namespace std;
int main()
{
    int n;char s;
    cin>>n>>s;
    if(n > 0)
    {
        int countn = 1;
        for(;countn <= n;countn++)
        {
            if(2*countn*countn-1 == n) break;
            else if(2*countn*countn-1 > n) {countn--;break;}
        }
        int counts = 2*countn-1;int countb = 0;
        for(int i = 0;i < countn-1;i++)
        {
            for(int j = 0;j < countb/2;j++) cout<<" ";
            for(int j = 0;j < counts;j++) cout<<s;
            counts -= 2;countb += 2;
            cout<<endl;
        }
        for(int i = 0;i < countn;i++)
        {
            for(int j = 0;j < countb/2;j++) cout<<" ";
            for(int j = 0;j < counts;j++) cout<<s;
            counts += 2;countb -= 2;
            cout<<endl;
        }
        cout<<(n-(2*countn*countn-1))<<endl;
    }
}
