//����ɵ��֮����1.һ���������֮��Ͳ�Ҫ������ո��ˣ������ʽ��
//2.����ʣ����٣���ʹ��0ҲҪ���������ڶ����жϵ��
//ʮ��ɵ�ƣ�

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
