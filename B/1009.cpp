#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> p;
    string temp;
    for(;cin>>temp;) p.push_back(temp);
    for(vector<string>::reverse_iterator it = p.rbegin();it != p.rend();it++) (it == p.rbegin() ? cout<<*it : cout<<" "<<*it);
    cout<<endl;
}
