//�����ɵ�ƣ�
//��һ�㡪��Ҳ������Ҫ��һ�㡪����TM��ô֪���ڼ�����ͬ�ַ��ǲ�������ͬ��λ�ã�����û����ȷ˵����
//�ڶ��㣬����2����ͬ���ַ���'E'������TM��ô֪���Ǵ�д�ַ�����Сд�ַ����������˵�˴�д��ĸA-N��ʾ����TM��ΪҪtoupper()һ�£�
//�����������������ɵ�ƣ���ɵ�ƣ�

#include <iostream>
#include <string>
using namespace std;

bool Judge(char a,int i)
{
    switch(i)
    {
        case 1:{if(a >= 'A' && a <= 'G'){return true;}else return false;}break;
        case 2:{if((a >= 'A' && a <= 'N') || (a >= '0' && a <= '9')){return true;}else return false;}break;
        case 3:{if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')){return true;}else return false;}break;
    }
}

void printDays(char c)
{
    switch(c)
    {
        case 'A':cout<<"MON ";break;
        case 'B':cout<<"TUE ";break;
        case 'C':cout<<"WED ";break;
        case 'D':cout<<"THU ";break;
        case 'E':cout<<"FRI ";break;
        case 'F':cout<<"SAT ";break;
        case 'G':cout<<"SUN ";break;
    }
}

void printHour(char c)
{
    if(c >= '0' && c <= '9') cout<<"0"<<c<<":";
    else if(c >= 'A' && c <= 'N') cout<<(int)(c - 'A' + 10)<<":";
}

void JudgeFirst(string a,string b)
{
    int flag;
    for(int i = 0;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],1) && Judge(b[i],1)))
        {
            printDays(a[i]);
            flag = i;
            break;
        }
    }
    for(int i = flag + 1;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],2) && Judge(b[i],2)))
        {
            printHour(a[i]);
            break;
        }
    }
}

void JudgeSecond(string a,string b)
{
    for(int i = 0;i < (a.length() > b.length() ? b.length() : a.length());i++)
    {
        if(a[i] == b[i] && (Judge(a[i],3) && Judge(b[i],3)))
        {
            cout<<i/10<<i%10<<endl;
            break;
        }
    }
}

int main()
{
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    JudgeFirst(a,b);
    JudgeSecond(c,d);
}
