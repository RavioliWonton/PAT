#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    double a,b;
    cin>>a>>b;
    cout<<setfill('0');
    cout<<setw(2)<<(long)round((b - a) / 100) / 3600<<":"<<setw(2)<<((long)round((b - a) / 100) - (long)round((b - a) / 100) / 3600 *3600) / 60<<":"<<setw(2)<<(long)round((b - a) / 100)  - ((long)round((b - a) / 100) / 3600 * 3600) - ((((long)round((b - a) / 100) - (long)round((b - a) / 100) / 3600 * 3600) / 60)*60)<<endl;
}
