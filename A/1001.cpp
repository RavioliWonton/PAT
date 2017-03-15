#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;
int main()
{
	int a,b;
	cin>>a>>b;
	stringstream ss;
	ss << (a+b);
	string s;
	ss >> s;
	ss.clear();
	ss.str("");
	int length = s.size();
    for(int i = length - 3;i > 0;i -= 3)
		if(i - 1 >= 0 && isdigit(s[i-1])) s.insert(i,1,',');
	cout<<s<<endl;
}
