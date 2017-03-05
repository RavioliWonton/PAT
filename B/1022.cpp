#include <iostream>
#include <sstream>
using namespace std;
int main()
{
	long a,b;int d;
	cin>>a>>b>>d;
    long c = a+b;
    if(!c) cout<<c<<endl;
    else
    {
        string s = "";
        stringstream ss;
        for(;c>0;)
        {
            string temp = "";
            ss << c%d;
            ss >> temp;
            ss.clear();
            ss.str("");
            temp += s;
            s = temp;
            c /= d;
        }
        cout<<s<<endl;
    }
}
