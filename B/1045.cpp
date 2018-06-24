#include <iostream>
#include <limits>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin>>n;
    deque<int> input,big,result;
    int small = numeric_limits<int>::max(),large = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
        big.push_back(large);
        if(temp > large) large = temp;
    }
    for(auto it = input.rbegin();it != input.rend();it++)
    {
        if(*it < small)
        {
            small = *it;
            if(*it > *(big.rbegin() + (it - input.rbegin()))) result.push_front(*it);
        }
    }
    cout<<result.size()<<endl;
    for(auto it = result.begin();it != result.end();it++)
        cout<<(it == result.begin() ? "" : " ")<<(*it);
    cout<<endl;
}
