#include <iostream>
#include <vector>
using namespace std;

auto ctoi = [&](char a)->int{return a - '0';};

const int calculateVerification(const string& a)
{
    int sum = 0;
    vector<int> p {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2}, m {1,0,10,9,8,7,6,5,4,3,2};
    for(auto it = next(a.rbegin());it != a.rend();it++)
    {
        if(isdigit(*it)) sum += (*next(p.rbegin(),distance(a.rbegin(),it) - 1))*ctoi(*it);
        else return -1;
    }
    return *next(m.begin(), sum % 11);
}

int main()
{
    int n;
    cin>>n;
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        string a;
        cin>>a;
        if(a.back() == 'X' && calculateVerification(a) != 10) {cout<<a<<endl;flag = false;}
        else if(a.back() != 'X' && calculateVerification(a) != ctoi(a.back())) {cout<<a<<endl;flag = false;}
    }
    if(flag) cout<<"All passed"<<endl;
}
