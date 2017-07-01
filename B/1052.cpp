#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> createList(string& a)
{
    vector<string> v;
    int i,j;
    for(i = a.find('['),j = a.find(']');i != string::npos && j != string::npos;i = a.find('[',j+1),j = a.find(']',j+1)) v.push_back(a.substr(i+1,j-i-1));
    return v;
}

bool judge(int n,vector<string> &v)
{
    if(n >= 0 && n < v.size()) return !v[n].empty();
    else return false;
}

int main()
{
    string a,b,c;
    getline(cin,a);vector<string> av = createList(a);
    getline(cin,b);vector<string> bv = createList(b);
    getline(cin,c);vector<string> cv = createList(c);
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int n1,n2,n3,n4,n5;
        cin>>n1>>n2>>n3>>n4>>n5;
        if(judge(n1-1,av) && judge(n5-1,av))
        {
            if(judge(n2-1,bv) && judge(n4-1,bv))
            {
                if(judge(n3-1,cv)) cout<<av[n1-1]<<"("<<bv[n2-1]<<cv[n3-1]<<bv[n4-1]<<")"<<av[n5-1]<<endl;
                else cout<<"Are you kidding me? @\\/@"<<endl;
            }
            else cout<<"Are you kidding me? @\\/@"<<endl;
        }
        else cout<<"Are you kidding me? @\\/@"<<endl;
    }
}
