//13~16行写成maxi = ((j - i + 1) > maxi ? j - i + 1 : maxi;就通过不了，不是很懂.......

#include <iostream>
#include <algorithm>
using namespace std;

long Calculate(long long *&s,long &n,long &p)
{
    long maxi = 0;
    for(long i = 0;i < n;i++)
    {
        for(long j = i + maxi;j < n;j++)
        {
            if((s[i] * p) >= s[j]) {if((j - i + 1) > maxi) maxi = j - i + 1;}
            else break;
        }
    }
    return maxi;
}

int main()
{
	long n,p;
	cin>>n>>p;
	long long (*s) = new long long[n];
	for(int i = 0;i < n;i++) cin>>s[i];
	sort(s,s+n);
    cout<<Calculate(s,n,p)<<endl;
    delete [] s;
}
