#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int jcu(char a)
{
    if(a >= 65 && a <= 90) return a-65;
    else return -1;
}

int jcd(char a)
{
    if(a >= 97 && a <= 122) return a-97;
    else return -1;
}

int jn(char a)
{
    if(a >= '0' && a <='9') return a-48;
    else return -1;
}

int main()
{
	string a,b;string u = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";string d = "abcdefghijklmnopqrstuvwxyz";
	cin>>a>>b;
	string c = "";
	bool (*pcu) = new bool[26];memset(pcu,false,sizeof(bool)*26);
	bool (*pcd) = new bool[26];memset(pcd,false,sizeof(bool)*26);
	bool (*pn) = new bool[10];memset(pn,false,sizeof(bool)*10);
	for(int i = 0;i < a.length();i++)
    {
        if(jcu(a[i]) != -1) pcu[jcu(a[i])] = true;
        else if(jcd(a[i]) != -1) pcd[jcd(a[i])] = true;
        else if(jn(a[i]) != -1) pn[jn(a[i])] = true;
    }
    /*for(int i = 0;i < a.length();i++)
    {
        if(jcu(a[i]) != -1)
        {
            if(u[jcu(a[i])] == a[i] && pcu[jcu(a[i])])
                c += a[i];
        }
        else if(jcd(a[i]) != -1)
        {
             if(d[jcd(a[i])] == a[i] && pcd[jcd(a[i])])
                c += a[i];
        }
        else if(jn(a[i]) != -1)
        {
            if((jn(a[i]) + 48) == a[i] && pn[jn(a[i])])
                c += a[i];
        }
    }*/
    for(int i = 0;i < 26;i++)
    {
        if(pcu[])
    }
    delete [] pcu;delete [] pcd;delete [] pn;u.~string();d.~string();
    cout<<c<<endl;
    for(int i = 0;i < c.length();i++)
    {
        if(b.find(c[i]) == b.npos)
        {
            if(jcd(c[i]) != -1) cout<<(char)(c[i]+32);
            else cout<<c[i];
        }
    }
    cout<<endl;
}
