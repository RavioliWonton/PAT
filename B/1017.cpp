#include <iostream>
#include <string>
using namespace std;

int main()
{
	string dividend,quotient = "";
    int divisor,remainder = 0;
	cin>>dividend>>divisor;
	if(dividend.size() == 1)
    {
        quotient = to_string(stoi(dividend) / divisor);
        remainder = stoi(dividend) % divisor;
    }
	else
	{
        for(auto it = dividend.begin();it != dividend.end();it++)
        {
            remainder *= 10;
            remainder += stoi(dividend.substr(distance(dividend.begin(),it),1));
            if(remainder / divisor)
            {
                quotient.append(to_string(remainder / divisor));
                remainder %= divisor;
            }
            else quotient.append("0");
        }
        if(quotient.front() == '0') quotient.erase(0,1);
    }
    cout<<quotient<<" "<<remainder<<endl;
}
