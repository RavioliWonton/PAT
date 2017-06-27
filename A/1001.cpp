#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	string s = to_string(a+b);
	int length = s.size();
    for(int i = length - 3;i > 0;i -= 3)
		if(i - 1 >= 0 && isdigit(s[i-1])) s.insert(i,1,',');
	cout<<s<<endl;
}
