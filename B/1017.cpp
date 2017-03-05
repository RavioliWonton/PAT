#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

int stoi(string c)
{
    stringstream ss;
    ss << c;
    int i;
    ss >> i;
    ss.clear();
    ss.str("");
    return i;
}

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
	string quotient = "";int remainder;
	bool (*isdivided) = new bool[dividend.length()];memset(isdivided,false,sizeof(bool)*dividend.length());
	for(int i = 0;i < dividend.length();i++)
    {
        if(!isdivided[i])
        {
            if(i != dividend.length()-2)
            {
                if(stoi(dividend.substr(i,1)) / divisor != 0)
                {
                    quotient += itos(stoi(dividend.substr(i,1)) / divisor);
                    if(stoi(dividend.substr(i,1)) % divisor != 0) dividend = itos(stoi(dividend.substr(i,1)) % divisor) + dividend.substr(i+1,dividend.length()-1);
                    else isdivided[i] = true;
                }
                else
                {
                    quotient += itos(stoi(dividend.substr(i,2)) / divisor);
                    if(stoi(dividend.substr(i,2)) % divisor != 0)
                    {
                        dividend = itos(stoi(dividend.substr(i,2)) % divisor) + dividend.substr(i+2,dividend.length()-2);
                        isdivided[i] = true;
                    }
                    else isdivided[i+1] = isdivided[i] = true;
                }
            }
            else
            {
                if(stoi(dividend.substr(i,1)) / divisor != 0)
                {
                    quotient += itos(stoi(dividend.substr(i,1)) / divisor);
                    quotient += itos(stoi(dividend.substr(i+1,1)) / divisor);
                    remainder = stoi(dividend.substr(i+1,1)) % divisor;
                    isdivided[i+1] = isdivided[i] = true;
                }
                else
                {
                    quotient += itos(stoi(dividend.substr(i,2)) / divisor);
                    remainder = stoi(dividend.substr(i,2)) % divisor;
                    isdivided[i+1] = isdivided[i] = true;
                }
            }
        }
    }
    delete [] isdivided;
    cout<<quotient<<" "<<remainder<<endl;
}
