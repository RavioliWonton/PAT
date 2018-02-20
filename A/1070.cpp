//重量不见得就是整数.......

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	double monovalent;
	double amount;
} mooncake;

int main()
{
	int n,d;
	cin>>n>>d;
	vector<mooncake> storage(n);
	for(int i = 0;i < 2*n;i++)
	{
		if(i < n) cin>>storage[i].amount;
		else
		{
			double price;
			cin>>price;
			storage[i - n].monovalent = price / storage[i - n].amount;
		}
	}
	sort(storage.begin(),storage.end(),[&](mooncake a,mooncake b)->bool {
		if(a.monovalent != b.monovalent) return a.monovalent > b.monovalent;
		else return a.amount < b.amount;
	});
	double sales = 0.0,income = 0.0;
	for(mooncake &a : storage)
	{
		if(sales < d)
		{
			double amount = 0;
			if(sales + a.amount <= d) amount = a.amount;
			else amount = d - sales;
			sales += amount;
			income += amount*a.monovalent;
		}
		else break;
	}
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<income<<endl;
}
