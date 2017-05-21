#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long n1,n2;
    vector<long> v1,v2;
    cin>>n1;
    for(int i = 0;i < n1;i++)
    {
        long temp;
        cin>>temp;
        v1.push_back(temp);
    }
    cin>>n2;
    for(int i = 0;i < n2;i++)
    {
        long temp;
        cin>>temp;
        v2.push_back(temp);
    }
    vector<long> v(n1+n2);
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v.begin());
    cout<<v[(n1+n2-1)/2]<<endl;
}
