#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string n;
	cin>>n;
	auto judge = [&](string n)->bool {
		auto itp = n.begin();
		auto itr = n.rbegin();
		for(;distance(n.begin(),itp) < n.size() / 2;itp++,itr++)
			if(*itp != *itr) return false;
		return true;
	};
	auto add = [&](string n,string rn)->string {
		string result = "";
		int carry = 0;
		for(int i = n.size() - 1;i >= 0;i--)
		{
			int sum = stoi(n.substr(i,1)) + stoi(rn.substr(i,1)) + carry;
			result = to_string(sum % 10) + result;
			carry = sum / 10;
		}
		return (carry ? to_string(carry) : "") + result;
	};
	for(int i = 0;i < 11;i++)
	{
		if(judge(n)) {cout<<n<<" is a palindromic number.\n";break;}
		else if(i == 10) cout<<"Not found in 10 iterations.\n";
		string rn;
		rn.resize(n.size());
		reverse_copy(n.begin(),n.end(),rn.begin());
		string sum = add(n,rn);
		if(i < 10) cout<< n << " + " << rn << " = "<< sum << "\n" ;
		n = sum;
	}
}
