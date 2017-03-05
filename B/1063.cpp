#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double maxmodulus = 0;
    for(int i = 0;i < n;i++)
    {
        int real,imaginary;
        cin>>real>>imaginary;
        double cmodulus = sqrt(pow(real,2) + pow(imaginary,2));
        if(cmodulus > maxmodulus) maxmodulus = cmodulus;
    }
    cout.setf(ios::fixed);
    cout<<setprecision(2)<<maxmodulus<<endl;
}
