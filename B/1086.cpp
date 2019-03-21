#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	string s(to_string(a*b));
	if(s.front() != '0')
    {
        for(;s.back() == '0';) s.pop_back();
        for(auto it = s.rbegin();it != s.rend();it++) cout<<*it;
    }
    else cout<<s;
	cout<<endl;
}
