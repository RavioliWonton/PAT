#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin>>n;
    deque<int> input,big,result;
    int small = 2147483647;int large = 0;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        input.push_back(temp);
        big.push_back(large);
        if(temp > large) large = temp;
    }
    for(deque<int>::reverse_iterator it = input.rbegin();it != input.rend();it++)
    {
        if(*it < small)
        {
            small = *it;
            if(*it > *(big.rbegin() + (it - input.rbegin()))) result.push_front(*it);
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
