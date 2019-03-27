#include <iostream>
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
        for(;c>0;)
        {
            string temp = to_string(c%d);
            temp += s;
            s = temp;
            c /= d;
        }
        cout<<s<<endl;
    }
}
