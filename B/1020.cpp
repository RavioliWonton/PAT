//库存也要用double，真智障.....

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef struct {
    double stock;
    double univalent;
} mooncake;

bool cmp(mooncake a,mooncake b)
{
    return a.univalent > b.univalent;
}

int main()
{
	int n,d;
	cin>>n>>d;
    mooncake (*p) = new mooncake[n];
    for(int i = 0;i < n;i++) cin>>p[i].stock;
    for(int i = 0;i < n;i++)
    {
        cin>>p[i].univalent;
        p[i].univalent /= p[i].stock;
    }
    sort(p,p+n,cmp);
    double sum = 0.0;double countn = 0;
    for(int i = 0;i < n;i++)
    {
        if(d - countn > 0)
        {
            sum += p[i].univalent*((d - countn) > p[i].stock ? p[i].stock : (d - countn));
            countn += ((d - countn) > p[i].stock ? p[i].stock : (d - countn));
        }
    }
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<sum<<endl;
    delete [] p;
}
