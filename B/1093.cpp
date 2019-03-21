#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string a,b;
    getline(cin,a);
    getline(cin,b);
    string c = a + b;
    for(auto itb = c.begin();itb != c.end();itb++)
    {
        auto ite = remove(next(itb),c.end(),*itb);
        c.resize(distance(c.begin(),ite));
    }
    cout<<c<<endl;
}
