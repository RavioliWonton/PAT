//库存也要用double，真智障.....

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    double stock;
    double univalent;
} mooncake;

int main()
{
	int n,d;
	cin>>n>>d;
    vector<mooncake> p;
    for(int i = 0;i < n;i++) 
    {
        double stock;
        cin>>stock;
        p.push_back({stock, 0});
    }
    for(int i = 0;i < n;i++)
    {
        cin>>(*(next(p.begin(),i))).univalent;
        (*(next(p.begin(),i))).univalent /= (*(next(p.begin(),i))).stock;
    }
    sort(p.begin(),p.end(),[&](auto a, auto b)->bool{return a.univalent > b.univalent;});
    double sum = 0.0, countn = 0;
    for(int i = 0;i < n;i++)
    {
        if(d - countn > 0)
        {
            sum += (*(next(p.begin(),i))).univalent*((d - countn) > (*(next(p.begin(),i))).stock ? (*(next(p.begin(),i))).stock : (d - countn));
            countn += ((d - countn) > (*(next(p.begin(),i))).stock ? (*(next(p.begin(),i))).stock : (d - countn));
        }
    }
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<sum<<endl;
}
