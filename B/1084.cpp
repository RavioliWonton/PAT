//题目有问题，待定。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int d,n;
	cin>>d>>n;
	vector<int> result;
	result.push_back(d);
	for(int i = 0;i < n;i++)
	{
		vector<int> temp;
		for(auto it = result.begin();it != result.end();)
		{
			auto range = equal_range(it,result.end(),*it);
			temp.push_back(*it);
			temp.push_back(range.second - range.first);
			it = range.second;
		}
		result.clear();
		result.assign(temp.begin(),temp.end());
		for_each(result.begin(),result.end(),[&](int i)->void{cout<<i;});
		cout<<endl;
		/*sort(result.begin(),result.end());
		vector<int> uresult(result.size());
		auto it = unique_copy(result.begin(),result.end(),uresult.begin());
		uresult.resize(distance(uresult.begin(),it));
		vector<int> counts;
		for(int &a : uresult)
		{
			counts.push_back(a);
			counts.push_back(count(result.begin(),result.end(),a));
		}*/
	}
	for_each(result.begin(),result.end(),[&](int i)->void{cout<<i;});
	cout<<endl;
}
