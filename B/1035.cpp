//不要看到inplace_merge就开开心心地用了，惨痛教训。

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

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
	if(equal(is_sorted_until(comparison.begin(),comparison.end()),comparison.end(),next(input.begin(), distance(comparison.begin(),is_sorted_until(comparison.begin(),comparison.end())))))
	{
		cout<<"Insertion Sort\n";
		sort(comparison.begin(),next(is_sorted_until(comparison.begin(),comparison.end(),less<int>()),1));
	}
    else
	{
		cout<<"Merge Sort\n";
		int length = 1;
		for(;(size_t)length < input.size();length *= 2)
		{
			for(int i = 0;i < n / length;i++) sort(next(input.begin(),i*length),next(input.begin(),(i+1)*length));
			sort(next(input.begin(),n / length * length),input.end());
			if(input == comparison) break;
		}
		length *= 2;
		for(int i = 0;i < n / length;i++) sort(next(comparison.begin(),i*length),next(comparison.begin(),(i+1)*length));
		sort(next(comparison.begin(),n / length * length),comparison.end());
	}
	for(auto it = comparison.begin();it != comparison.end();it++)
		cout<<(it != comparison.begin() ? " " : "")<<(*it);
	cout<<endl;
}
