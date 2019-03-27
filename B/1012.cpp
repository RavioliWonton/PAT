#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n1 = 0,n2 = 0,n3 = 0,n5 = 0,n,countn1 = 0,countn2 = 0;
    double n4 = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        if(!(temp % 10)) n1 += temp;
        else if(temp % 5 == 1) {if(!(countn1 % 2)) n2 += temp;else n2 -= temp;countn1++;}
        else if(temp % 5 == 2) n3++;
        else if(temp % 5 == 3) {countn2++;n4 += temp;}
        else if(temp % 5 == 4) n5 = (temp > n5 ? temp : n5);
    }
    cout<<(n1 ? to_string(n1) : "N")<<" "<<(countn1 ? to_string(n2) : "N")<<" "<<(n3 ? to_string(n3) : "N")<<" ";
    cout.setf(ios::fixed);
    if(countn2) cout<<setprecision(1)<<n4 / countn2<<" ";
    else cout<<"N ";
    cout.unsetf(ios::fixed);
    cout<<(n5 ? to_string(n5) : "N")<<endl;
}
