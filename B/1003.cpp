#include <iostream>
#include <string>
using namespace std;
bool isString(string s)
{
	for (int i = 0;i < s.length();i++)
	{
		if (s[i] != 'P' && s[i] != 'A' && s[i] != 'T')
			return false;
	}
	return true;
}
bool isPAT(string s)
{
	int indexP = s.find('P', 0), indexT = s.find('T', 0), countAbP = 0, countAbPT = 0, countAaT = 0, i;
	if (indexP > indexT || indexP + 1 == indexT) return false;
	else
	{
		if (indexP == 0) countAbP = 0;
		else
        {
            for (i = 0;i < indexP;i++)
                if (s[i] == 'A') countAbP++;
                else return 0;
        }
        for (i = indexP+1;i < indexT;i++)
            if (s[i] == 'A') countAbPT++;
        	else return 0;
        if (indexT == s.length()) countAaT = s.length();
        else
        {
            for (i = indexT+1;i < s.length();i++)
                if (s[i] == 'A') countAaT++;
                else return 0;
        }
        if (countAbP*countAbPT == countAaT)
            return 1;
	}
	return 0;
}
int main()
{
	int n;string s;
	cin >> n;
	for (;n > 0;n--)
	{
		cin >> s;
		if(isString(s))cout<<"NO"<<endl;
		else if(isPAT(s))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
