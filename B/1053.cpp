#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n,d;double e;
	cin>>n>>e>>d;
	int pv = 0;int  v = 0;
    for(int i = 0;i < n;i++)
    {
        int m;int l = 0;
        cin>>m;
        for(int j = 0;j < m;j++)
        {
            double temp;
            cin>>temp;
            if(temp < e) l++;
        }
        if(l > (double)m/2)
        {
            if(m > d) v++;
            else pv++;
        }
    }
    cout.setf(ios::fixed);
    cout<<setprecision(1)<<((double)pv/(double)n)*100<<"% "<<setprecision(1)<<((double)v/(double)n)*100<<"%"<<endl;
}
