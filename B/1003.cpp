#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPAT(string s)
{
	int countAbP = 0, countAbPT = 0, countAaT = 0;
	string::iterator indexP = find(s.begin(),s.end(),'P');
	string::iterator indexT = find(s.begin(),s.end(),'T');
	if (indexP > indexT || indexP + 1 == indexT) return false;
	else
	{
		if (indexP != s.begin())
        {
            for (string::iterator it = s.begin();it != indexP;it++)
            {
                if (*it == 'A') countAbP++;
                else return false;
            }
        }
        for (string::iterator it = indexP + 1;it != indexT;it++)
        {
            if (*it == 'A') countAbPT++;
        	else return false;
        }
        if (indexT != s.end() - 1)
        {
            for (string::iterator it = indexT + 1;it != s.end();it++)
            {
                if (*it == 'A') countAaT++;
                else return false;
            }
        }
        if (countAbP*countAbPT == countAaT) return true;
        else return false;
	}
}
int main()
{
	int n;string s;
	cin >> n;
	for (;n > 0;n--)
	{
		cin >> s;
		if(isPAT(s)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
