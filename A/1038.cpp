#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i = 0;i < n;i++)
    {
        int tempi;
        cin>>tempi;
        if(tempi) v.push_back(to_string(tempi));
    }
    sort(v.begin(),v.end(),[&](string a,string b)->bool{return a + b <= b + a;});
    if(v.size())
    {
        for(auto it = v.begin();it != v.end();it++)
        {
            if(it == v.begin()) cout<<stoi(*it);
            else cout<<*it;
        }
    }
    else cout<<"0";
    cout<<endl;
}
