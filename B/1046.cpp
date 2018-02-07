#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,r1 = 0,r2 = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        vector<int> p(4);
        for(int j = 0; j < 4;j++) cin>>p[j];
        if(p[0] + p[2] == p[1] && p[0] + p[2] == p[3]) continue;
        else if(p[0] + p[2] == p[3]) r1++;
        else if(p[0] + p[2] == p[1]) r2++;
    }
    cout<<r1<<" "<<r2<<endl;
}
