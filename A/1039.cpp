#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int convert(const string& name)
{
    auto f = [&](const char& c)->string{return ((c - '@' < 10) ? ('0' + to_string(c - '@')) : to_string(c - '@'));};
    return stoi(f(name[0]) + f(name[1]) + f(name[2]) + name[3]);
}

constexpr int cc(int& i)
{
    return i;
}

int main()
{
    int n,k;
    cin>>n>>k;
    const int ck = cc(k);
    bitset<10000000*(ck+1)> b;
    for(int i = 0;i < k;i++)
    {
        int num,counts;
        cin>>num>>counts;
        for(int j = 0;j < counts;j++)
        {
            string name;
            cin>>name;
            int nid = convert(name);
            if(!b.test(nid * (k + 1))) b.set(nid * (k + 1));
            b.set(nid * (k + 1) + num);
        }
    }
    for(int i = 0;i < n;i++)
    {
        string name;
        cin>>name;
        cout<<name<<" ";
        int nid = convert(name);
        if(b.test(nid * (k + 1)))
        {
            int countn = 0;
            vector<int> v;
            for(int j = nid * (k + 1) + 1;j < (nid + 1) * (k + 1);j++)
            {
                if(b.test(j))
                {
                    countn++;
                    v.push_back(j - nid * (k + 1));
                }
            }
            cout<<countn<<endl;
            if(countn) for_each(v.begin(),v.end(),[&](int i)->void{cout<<" "<<i;});
        }
        else cout<<"0"<<endl;
    }
}
