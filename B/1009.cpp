#include <iostream>
using namespace std;
int main()
{
	string (*p) = new string[80];int countn = 0;
	for(;cin>>p[countn];) {countn++;}
	cout<<p[countn - 1];
    for(int i = countn - 2;i >= 0;i--)
        cout<<" "<<p[i];
    cout<<endl;
    delete [] p;
}
