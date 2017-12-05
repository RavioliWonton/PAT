#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    map<int,double,greater<int> > base,polynomial;
    for(int i = 0; i < 2; i++)
    {
        int n;
        cin>>n;
        for(int j = 0; j < n; j++)
        {
            int exponents;
            double coefficients;
            cin>>exponents>>coefficients;
            if(i)
                for(auto &x : base) polynomial[exponents + x.first] += coefficients*x.second;
            else base[exponents] += coefficients;
        }
    }
    for(auto& x : polynomial)
        if(!x.second) polynomial.erase(x.first);
    cout<<polynomial.size();
    cout.setf(ios::fixed);
    for(auto& x : polynomial) cout<<" "<<x.first<<" "<<setprecision(1)<<x.second;
}
