#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    bitset<104730> pb;
    pb.set();
    for(int i = 2;i < sqrt(104730);i++)
    {
        if(pb.test(i))
            for(int j = i;i*j < 104730;j++) pb.reset(i*j);
    }
    vector<int> pi(10001);
    int pj = 1,m,n;
    for(int i = 2;i < 104730;i++)
    {
        if(pb.test(i))
        {
            pi[pj] = i;
            pj++;
        }
    }
    cin>>m>>n;
    for(int i = m;i <= n;i++)
    {
        if((i - m + 1)%10 != 0 && i != n) cout<<pi[i]<<" ";
        else cout<<pi[i]<<"\n";
    }
}
