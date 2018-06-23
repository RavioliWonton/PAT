#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> p;
    for(int i = 0;i < n;i++)
	{
		int input;
		cin>>input;
		p.push_back(input);
	}
    set<int> f;
    for(int i = 0;i < n;i++)
    {
    	auto func = [&](int a)->int {
			int sum = 0;
			for(;a >= 10;)
			{
				sum += a%10;
				a /= 10;
			}
			return sum + a;
		};
		int num = func(*next(p.begin(),i));
        if(!f.count(num)) f.insert(num);
    }
    cout<<f.size()<<endl;
    cout<<*f.begin();
    for(auto it = next(f.begin(),1);it != f.end();advance(it,1)) cout<<" "<<(*it);
    cout<<endl;
}
