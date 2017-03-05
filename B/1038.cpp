//这又是另一个不能用结构体，只能用稀疏表的实例......

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int (*p) = new int[101];memset(p,0,sizeof(int)*101);
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        p[temp]++;
    }
    int m;
    cin>>m;
    int query;
    cin>>query;
    cout<<p[query];
    for(int i = 1;i < m;i++)
    {
        cin>>query;
        cout<<" "<<p[query];
    }
    cout<<endl;
    delete [] p;
}
