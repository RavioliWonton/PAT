#include <iostream>
using namespace std;
int main()
{
	int n,r1,r2;
	r1 = r2 = 0;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        int (*p) = new int[4];
        for(int j = 0; j < 4;j++) cin>>p[j];
        if(p[0] + p[2] == p[1] && p[0] + p[2] == p[3]) {delete [] p;continue;}
        else if(p[0] + p[2] == p[3]) {r1++;delete [] p;}
        else if(p[0] + p[2] == p[1]) {r2++;delete [] p;}
        else {delete [] p;continue;}
    }
    cout<<r1<<" "<<r2<<endl;
}
