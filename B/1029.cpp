#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    string p = "";
    for(;a.size();)
    {
        if(a.front() != b.front())
        {
            if((p.find(toupper(a.front())) == string::npos) && (p.find(tolower(a.front())) == string::npos))
                p.push_back(*a.begin());
        }
        else b.erase(0,1);
        a.erase(0,1);
    }
    transform(p.begin(),p.end(),p.begin(),::toupper);
    cout<<p<<endl;
}
