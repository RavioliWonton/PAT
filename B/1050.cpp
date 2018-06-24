#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getwidth(const int& n)
{
    int mini = n,width = 1;
    for(int i = 2;i < n-1;i++)
    {
        if(!(n % i) && (n/i > i ? n/i : i) - (n/i < i ? n/i : i) < mini)
        {
            width = (n/i > i ? n/i : i);
            mini = width - (n/i < i ? n/i : i);
        }
    }
    return width;
}

int main()
{
	int n;
	cin>>n;
	vector<int> p(n);
    for(int i = 0;i < n;i++) cin>>p[i];
    sort(p.begin(),p.end(),greater_equal<int>());
    int width = getwidth(n);
    if(width == 1)
        for(auto& a : p) cout<<a<<"\n";
    else
    {
        vector<vector<int> > o(width,vector<int>(n / width));
        int rowflag1 = 0,rowflag2 = width - 1,arrayflag1 = 0,arrayflag2 = n / width - 1,flag = 0;
        for(;flag < n;)
        {
            if(arrayflag1 != arrayflag2 && flag < n)
            {
                for(int i = arrayflag1;i <= arrayflag2;i++) {o[rowflag1][i] = p[flag];flag++;}
                rowflag1++;
            }
            if(rowflag1 != rowflag2 && flag < n)
            {
                for(int i = rowflag1;i <= rowflag2;i++) {o[i][arrayflag2] = p[flag];flag++;}
                arrayflag2--;
            }
            if(arrayflag1 != arrayflag2 && flag < n)
            {
                for(int i = arrayflag2;i >= arrayflag1;i--) {o[rowflag2][i] = p[flag];flag++;}
                rowflag2--;
            }
            if(rowflag1 != rowflag2 && flag < n)
            {
                for(int i = rowflag2;i >= rowflag1;i--) {o[i][arrayflag1] = p[flag];flag++;}
                arrayflag1++;
            }
        }
        for(auto& a : o)
        {
            for(auto it = a.begin();it != a.end();it++) cout<<(it == a.begin() ? "" : " ")<<(*it);
            cout<<"\n";
        }
	}
}
