#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

string add(string n,string rn)
{
	string sum = "";int carry = 0;
	for(int i = n.size() - 1;i >= 0;i--)
	{
        int result = (n[i] - '0') + (rn[i] - '0') + carry;
        if(i) {carry = result / 10;result %= 10;}
        sum = to_string(result) + sum;
	}
	return sum;
}

bool isPalindromic(string str)
{
	string str1 = str.substr(0,ceil((double)(str.size())/2));
	string str2 = str.substr(floor((double)(str.size())/2));
    reverse(str2.begin(),str2.end());
    return (str1 == str2 ? true : false);
}

int main()
{
	string number;int k;
	cin>>number>>k;
	int countn = 0;
	for(;!isPalindromic(number) && countn < k;)
	{
		string temp = number;
		reverse(number.begin(),number.end());
		number = add(number,temp);
		countn++;
	}
	cout<<number<<"\n"<<countn<<endl;
}
