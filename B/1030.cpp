//19行写成maxi = ((j - i + 1) > maxi ? j - i + 1 : maxi;就通过不了，不是很懂.......

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	long n,p,maxi = 0;
	cin>>n>>p;
	vector<long long> s(n);
	for(int i = 0;i < n;i++) cin>>s[i];
	sort(s.begin(),s.end());
	for(long i = 0;i < n;i++)
    {
        for(long j = i + maxi;j < n;j++)
        {
            if((s[i] * p) >= s[j]) {if((j - i + 1) > maxi) maxi = j - i + 1;}
            else break;
        }
    }
    cout<<maxi<<endl;
}
