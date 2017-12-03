#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    map<int,double,greater<int> > polynomial;
    for(int i = 0; i < 2; i++)
    {
        cin>>n;
        for(int j = 0; j < n; j++)
        {
            int exponents;
            double coefficients;
            cin>>exponents>>coefficients;
            polynomial[exponents] += coefficients;
        }
    }
    for(auto& x : polynomial)
        if(x.second == 0) polynomial.erase(x.first);
    cout<<polynomial.size();
    cout.setf(ios::fixed);
    for(auto& x : polynomial) cout<<" "<<x.first<<" "<<setprecision(1)<<x.second;
}
