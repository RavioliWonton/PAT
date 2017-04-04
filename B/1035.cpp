#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printvector(vector<int> &v)
{
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		if(it == v.begin()) cout<<*it;
		else cout<<" "<<*it;
	}
	cout<<endl;
}

int main()
{
	int n;
	cin>>n;
	vector<int> input,comparison;
    for(int i = 0;i < n;i++)
	{
		int temp;
		cin>>temp;
		input.push_back(temp);
	}
	for(int i = 0;i < n;i++)
	{
		int temp;
		cin>>temp;
		comparison.push_back(temp);
	}
	if(equal(is_sorted_until(comparison.begin(),comparison.end()),comparison.end(),input.begin() + (is_sorted_until(comparison.begin(),comparison.end()) - comparison.begin())))
	{
		cout<<"Insertion Sort"<<endl;
		sort(comparison.begin(),is_sorted_until(comparison.begin(),comparison.end(),less<int>()) + 1);
		printvector(comparison);
	}
    else
	{
		cout<<"Merge Sort"<<endl;
		vector<int>::iterator first = comparison.begin();
		vector<int>::iterator middle = is_sorted_until(comparison.begin(),comparison.end());
		vector<int>::iterator last = (comparison.end() - middle > middle - first ? middle + (middle - first) : comparison.end());
		for(;first != middle;)
		{
			inplace_merge(first,middle,last);
			first = last;
			middle = (comparison.end() - last >= 2*(last - middle) ? last + (last - middle) : last);
			last = ((middle != last && comparison.end() - last > 2*(last - middle)) ? middle + (middle - first) : comparison.end());
		}
		printvector(comparison);
	}
}
