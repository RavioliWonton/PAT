#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
	char buffer;
	deque<int> v1;
	for(;(buffer = cin.get()) && (buffer != '\n');) v1.push_back(buffer - '0');
	deque<int> v2(v1.size());
	int carry = 0;int position = v1.size();
	generate(v2.rbegin(),v2.rend(),
			[v1,&position,&carry]
			{
				int i = v1[--position]*2 + carry;
				carry = i / 10;
				return i % 10;
			});
	if(carry) v2.push_front(carry);
	deque<int> v3(v2);
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	if(v1 == v2) cout<<"Yes\n";
	else cout<<"No\n";
	for_each(v3.begin(),v3.end(),[&](int i) -> void {cout<<i;});
	cout<<endl;
}
