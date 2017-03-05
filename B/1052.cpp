#include <iostream>
#include <string>
using namespace std;

string* createList(string a)
{
    string (*p) = new string[11];int countn = 1;
    for(int i = 0;i < a.length();)
    {
        if(a[i] == '[')
        {
            for(int j = i;j < a.length();)
            {
                if(a[j] == ']')
                {
                    p[countn] = a.substr(i + 1,j - i - 1);
                    i = j + 1;
                    countn++;
                    break;
                }
                else j++;
            }
        }
        else i++;
    }
    return p;
}

int main()
{
    string a,b,c;
    getline(cin,a);getline(cin,b);getline(cin,c);
    string (*ap) = createList(a);string (*bp) = createList(b);string (*cp) = createList(c);
    int n;
    cin>>n;
    int n1,n2,n3,n4,n5;
    for(int i = 0;i < n;i++)
    {
        cin>>n1>>n2>>n3>>n4>>n5;
        if(!ap[n1].empty() && !ap[n5].empty())
        {
            if(!bp[n2].empty() && !bp[n4].empty())
            {
                if(!cp[n3].empty())
                    cout<<ap[n1]<<"("<<bp[n2]<<cp[n3]<<bp[n4]<<")"<<ap[n5]<<endl;
                else cout<<"Are you kidding me? @\\/@"<<endl;
            }
            else cout<<"Are you kidding me? @\\/@"<<endl;
        }
        else cout<<"Are you kidding me? @\\/@"<<endl;
    }
    delete [] ap;delete [] bp;delete [] cp;
}
