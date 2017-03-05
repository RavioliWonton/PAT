#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int n;
	cin>>n;
	double sum = 0.0;
	for(int i = 0;i < n;i++)
    {
        double temp;
        cin>>temp;
        sum += temp*(i+1)*(n-i);
    }
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<sum<<endl;
}
