#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    long long countT = 0;long long countAT = 0;long long countPAT = 0;
    for(int i = s.size()-1;i >= 0;i--)
    {
        switch(s[i])
        {
            case 'T':countT++;break;
            case 'A':countAT += countT;break;
            case 'P':countPAT += countAT;break;
        }
    }
    cout<<countPAT % 1000000007<<endl;
}
