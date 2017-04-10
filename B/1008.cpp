#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    m %= n;
    deque<int> p;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        p.push_back(temp);
    }
    for(int i = 0;i < m;i++)
    {
        int temp = p.back();
        p.pop_back();
        p.push_front(temp);
    }
    bool flag = true;
    for(int & i : p)
    {
        if(flag) {cout<<i;flag = false;}
        else cout<<" "<<i;
    }
    cout<<endl;
}
