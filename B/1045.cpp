#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> input,big;
    int small = 2147483647;int large = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
        big.push_back(large);
        if(temp > large) large = temp;
    }
    deque<int> result;
    for(int i = n - 1;i >= 0;i--)
    {
        if(input[i] < small)
        {
            small = input[i];
            if(input[i] > big[i]) result.push_front(input[i]);
        }
    }
    cout<<result.size()<<endl;
    bool flag = true;
    for(deque<int>::iterator it = result.begin();it != result.end();it++)
    {
        if(flag)
        {
            cout<<*it;
            flag = false;
        }
        else cout<<" "<<*it;
    }
    cout<<endl;
}
