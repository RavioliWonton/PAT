#include <iostream>
#include <sstream>
#include <string>
using namespace std;

string itos(int i)
{
    stringstream ss;
    ss << i;
    string s;
    ss >> s;
    ss.clear();
    ss.str("");
    return s;
}

int main()
{
    string dividend;int divisor;
    cin>>dividend>>divisor;
    string quotient = "";int remainder = 0;
    if(dividend.size() == 1)
    {
        quotient = itos(stoi(dividend) / divisor);
        remainder = stoi(dividend) % divisor;
    }
    else
    {
        for(int i = 0;i < dividend.size();i++)
        {
            remainder *= 10;
            remainder += stoi(dividend.substr(i,1));
            if(remainder / divisor)
            {
                quotient.append(itos(remainder / divisor));
                remainder %= divisor;
            }
            else quotient.append("0");
        }
        if(quotient.substr(0,1) == "0") quotient.erase(0,1);
    }
    cout<<quotient<<" "<<remainder<<endl;
}
