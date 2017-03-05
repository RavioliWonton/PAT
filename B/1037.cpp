#include <iostream>
#include <sstream>
#include <string>
using namespace std;

long changeMoney(string s)
{
    stringstream ss;
    ss << s.substr(0,s.find('.'));
    long m;
    ss >> m;
    ss.clear();
    ss.str("");
    m *= 493;
    ss << s.substr(s.find('.') + 1,s.rfind('.') - s.find('.') - 1);
    int temp;
    ss >> temp;
    ss.clear();
    ss.str("");
    m += 29*temp;
    ss << s.substr(s.rfind('.') + 1,s.length() - s.rfind('.') - 1);
    ss >> temp;
    m += temp;
    return m;
}

int main()
{
    string a,b;
    cin>>a>>b;
    long am = changeMoney(a);long bm = changeMoney(b);
    if(bm >= am) cout<<(bm - am) / 493<<"."<<(bm - am - ((bm - am) / 493)*493) / 29<<"."<<(bm - am - ((bm - am) / 493)*493) % 29<<endl;
    else cout<<"-"<<(am - bm) / 493<<"."<<(am - bm - ((am - bm) / 493)*493) / 29<<"."<<(am - bm - ((am - bm) / 493)*493) % 29<<endl;
}
