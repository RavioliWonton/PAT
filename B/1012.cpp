#include <iostream>
#include <iomanip>
using namespace std;

void printNumber(int n)
{
    if(n) cout<<n;
    else cout<<"N";
}

void printNumber(int n,int countn)
{
    if(countn) cout<<n;
    else cout<<"N";
}

void printNumber(double n,int countn)
{
    cout.setf(ios::fixed);
    if(n) cout<<setprecision(1)<<n / countn;
    else cout<<"N";
    cout.unsetf(ios::fixed);
}

int main()
{
	int n1 = 0;int n2 = 0;int n3 = 0;double n4 = 0;int n5 = 0;int n;int countn1 = 0;int countn2 = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        if(!(temp % 10)) n1 += temp;
        if(temp % 5 == 1) {if(!(countn1 % 2)) n2 += temp;else n2 -= temp;countn1++;}
        if(temp % 5 == 2) n3++;
        if(temp % 5 == 3) {countn2++;n4 += temp;}
        if(temp % 5 == 4) n5 = (temp > n5 ? temp : n5);
    }
    printNumber(n1);cout<<" ";
    printNumber(n2,countn1);cout<<" ";
    printNumber(n3);cout<<" ";
    printNumber(n4,countn2);cout<<" ";
    printNumber(n5);cout<<endl;
}
