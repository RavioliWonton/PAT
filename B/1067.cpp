#include <iostream>
#include <limits>
#include <string>
using namespace std;
int main()
{
	string answer,temp;int n,countn;
	cin>>answer>>n;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	countn = 0;
	for(;(getline(cin,temp)) && (temp != "#");)
	{
		countn++;
		if(countn < n)
		{
			if(temp == answer)
			{
				cout<<"Welcome in"<<endl;
				break;
			}
			else
			{
                cout<<"Wrong password: "<<temp<<endl;
                continue;
			}
		}
		else if(countn = n)
		{
			if(temp == answer)
			{
				cout<<"Welcome in"<<endl;
				break;
			}
			else
			{
                cout<<"Wrong password: "<<temp<<endl<<"Account locked"<<endl;
				break;
			}
		}
		else break;
	}
}
