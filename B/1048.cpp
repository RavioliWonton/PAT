#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int ctoi(char c)
{
    return (int)(c - 48);
}

char itoc(int i)
{
    return (char)(i + 48);
}

string completation(string mins,string &maxs)
{
    int difference = maxs.length() - mins.length();
    for(int i = 0;i < difference;++i)
        mins = "0"+mins;
    return mins;
}

int main()
{
	string a,b;
    cin>>a>>b;
    (a.length() < b.length() ? a : b) = completation((a.length() < b.length() ? a : b),(a.length() > b.length() ? a : b));
    for(int i = b.length() - 1;i >= 0;i--)
    {
        if((b.length() - i) % 2 != 0)
        {
            switch((ctoi(a[i]) + ctoi(b[i])) % 13)
            {
                case 12:b[i] = 'K';break;
                case 11:b[i] = 'Q';break;
                case 10:b[i] = 'J';break;
                default:b[i] = itoc((ctoi(a[i]) + ctoi(b[i])) % 13);break;
            }
        }
        else
        {
            if(ctoi(b[i]) - ctoi(a[i]) < 0)
                b[i] = itoc(10 + ctoi(b[i]) - ctoi(a[i]));
            else b[i] = itoc(ctoi(b[i]) - ctoi(a[i]));
        }
    }
    cout<<b<<endl;
}
