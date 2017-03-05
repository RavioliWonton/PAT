#include <iostream>
#include <sstream>
using namespace std;

string itos(int n)
{
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    ss.clear();
    ss.str("");
    return s;
}

int main()
{
    int n,m;
    cin>>n>>m;
    m %= n;
    m = n - m;
    string s = "";string fs = "";
    bool flag1 = false;bool flag2 = false;
    for(int i = 1;i <= n;i++)
    {
        int tempn;
        cin>>tempn;
        if(m == n)
        {
            if(!flag1)
            {
                s = itos(tempn);
                flag1 = true;
            }
            else
            {
                string temps = itos(tempn);
                temps = " "+temps;
                s += temps;
            }
        }
        else if(n == 1) {s = itos(tempn);}
        else
        {
            if(i == m)
            {
                string temps = itos(tempn);
                temps = " " + temps;
                fs += temps;
                flag2 = true;
            }
            else
            {
                if(!flag1 && flag2)
                {
                    s = itos(tempn);
                    flag1 = true;
                }
                else
                {
                    if(flag2)
                    {
                        string temps = itos(tempn);
                        temps = " " + temps;
                        s += temps;
                    }
                    else
                    {
                        string temps = itos(tempn);
                        temps = " " + temps;
                        fs += temps;
                    }
                }
            }
        }
    }
    s += fs;
    cout<<s<<endl;
}
