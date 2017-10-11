#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v(m);
	for(int i = 0;i < m;i++) cin>>v[i];
	int sum1 = 0,sum2 = 0;
	for(int i = 0;i < n;i++)
    {
        string name;
        int countn;
        bool flag = true;
        cin>>name>>countn;
        for(int j = 0;j < countn;j++)
        {
            int temp;
            cin>>temp;
            if(find(v.begin(),v.end(),temp) != v.end())
            {
                if(flag)
                {
                    cout<<name<<":";
                    sum1++;
                    flag = false;
                }
                sum2++;
                cout<<" "<<setw(4)<<setfill('0')<<temp;
            }
        }
        if(!flag) cout<<endl;
    }
    cout<<sum1<<" "<<sum2<<endl;
}
