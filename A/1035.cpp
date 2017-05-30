#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string out = (n > 1 ? "are "+to_string(n)+" accounts" : "is "+to_string(n)+" account");
	ostringstream ss;
	int countn = 0;
	for(int i = 0;i < n;i++)
    {
        string user,password;
        cin>>user>>password;
        if(password.find("1") != string::npos || password.find("0") != string::npos || password.find("O") != string::npos || password.find("l") != string::npos)
        {
            countn++;
            ss<<user<<" ";
            replace(password.begin(),password.end(),'1','@');
            replace(password.begin(),password.end(),'0','%');
            replace(password.begin(),password.end(),'O','o');
            replace(password.begin(),password.end(),'l','L');
            ss<<password<<"\n";
        }
    }
    if(countn) cout<<countn<<"\n"<<ss.str();
    else cout<<"There "<<out<<" and no account is modified"<<endl;
}
