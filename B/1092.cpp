#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> sales(n,0);
    for(int i = 0;i < m;i++)
    {
        for(int j = 0;j < n;j++)
        {
            int sale;
            cin>>sale;
            sales[j] += sale;
        }
    }
    cout<<*max_element(sales.begin(),sales.end())<<"\n"<<distance(sales.begin(),max_element(sales.begin(),sales.end())) + 1;
    for(auto it = find(next(max_element(sales.begin(),sales.end())),sales.end(),*max_element(sales.begin(),sales.end()));it != sales.end();it = find(next(it),sales.end(),*max_element(sales.begin(),sales.end())))
        cout<<" "<<distance(sales.begin(),it) + 1;
    cout<<endl;
}
