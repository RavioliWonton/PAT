#include <iostream>
#include <string>
using namespace std;

int main()
{
	string dividend;int divisor;
	cin>>dividend>>divisor;
	string quotient = "";int remainder = 0;
	if(dividend.size() == 1)
    {
        quotient = to_string(stoi(dividend) / divisor);
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
                quotient.append(to_string(remainder / divisor));
                remainder %= divisor;
            }
            else quotient.append("0");
        }
        if(quotient.front() == '0') quotient.erase(0,1);
    }
    cout<<quotient<<" "<<remainder<<endl;
}
