#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int, int> > ans(m);
    for(int i = 0;i < m;i++) cin>>ans[i].first;
    for(int i = 0;i < m;i++) cin>>ans[i].second;
    for(int i = 0;i < n;i++)
    {
        int grade = 0;
        for(int j = 0;j < m;j++)
        {
            int temp;
            cin>>temp;
            if(!(temp ^ ans[j].second)) grade += ans[j].first;
        }
        cout<<grade<<"\n";
    }
}
