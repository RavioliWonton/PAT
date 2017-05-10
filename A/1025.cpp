#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	string number;
	int location;
	int score;
	int total_rank;
	int location_rank;
} testee;

int main()
{
	int n;
	cin>>n;
	vector<testee> v;
	int position = 0;
	for(int i = 0;i < n;i++)
	{
		int k;
		cin>>k;
		vector<testee> pv;
		for(int j = 0;j < k;j++)
		{
			testee temp;
			cin>>temp.number>>temp.score;
			temp.location = i + 1;
			pv.push_back(temp);
		}
		sort(pv.begin(),pv.end(),[&](testee a,testee b) -> bool {if(a.score != b.score) return a.score > b.score;else return a.number < b.number;});
		int countn = 0;int tempscore = 101;int tempn = 0;
		for(testee& p : pv)
		{
			countn++;
			if(p.score == tempscore) p.location_rank = tempn;
			else
			{
				p.location_rank = countn;
				tempscore = p.score;
				tempn = p.location_rank;
			}
		}
		v.resize(v.size()+k);
		copy(pv.begin(),pv.end(),(v.begin()+position));
		position += k;
	}
	sort(v.begin(),v.end(),[&](testee a,testee b) -> bool {if(a.score != b.score) return a.score > b.score;else return a.number < b.number;});
	int countn = 0;int tempscore = 101;int tempn = 0;
	for(testee& p : v)
	{
		countn++;
		if(p.score == tempscore) p.total_rank = tempn;
		else
		{
			p.total_rank = countn;
			tempscore = p.score;
			tempn = p.total_rank;
		}
	}
	sort(v.begin(),v.end(),[&](testee a,testee b) -> bool {if(a.total_rank != b.total_rank) return a.total_rank < b.total_rank;else return a.number < b.number;});
	cout<<v.size()<<endl;
	for_each(v.begin(),v.end(),[&](testee p)->void{cout<<p.number<<" "<<p.total_rank<<" "<<p.location<<" "<<p.location_rank<<"\n";});
}
