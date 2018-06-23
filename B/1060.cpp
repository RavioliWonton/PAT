//不能set，否则超时。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n,a = 0;
    cin>>n;
    vector<int> p;
    for(int i = 0;i < n;i++)
    {
        int input;
        cin>>input;
        p.push_back(input);
    }
    sort(p.begin(),p.end(),greater_equal<int>());
    for(int j = 1;j < n + 1;j++)
        if(*next(p.begin(),j - 1) > j) a++;
    cout<<a<<endl;
}
