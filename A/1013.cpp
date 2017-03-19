#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

struct compf {
	compf(int const &i) :_i(i) {}
	bool operator() (pair<int,int> const& p) {return p.first == _i;}
	int _i;
};

struct comps {
	comps(int const &i) :_i(i) {}
	bool operator() (pair<int,int> const& p) {return p.second == _i;}
	int _i;
};

int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<pair<int,int> > p;
	for(int i = 0;i < m;i++)
	{
		int first,second;
		cin>>first>>second;
		if(first <= n && second <= n) p.push_back(make_pair(first,second));
	}
	for(int i = 0;i < k;i++)
	{
		int request;
		cin>>request;
		vector<int> pn;
		vector<pair<int,int> > pc(p);
        for(;;)
		{
			if(find_if(pc.begin(),pc.end(),compf(request)) != pc.end())
			{
				pn.push_back(find_if(pc.begin(),pc.end(),compf(request))->second);
				pc.erase(find_if(pc.begin(),pc.end(),compf(request)));
			}
			else if(find_if(pc.begin(),pc.end(),comps(request)) != pc.end())
			{
				pn.push_back(find_if(pc.begin(),pc.end(),comps(request))->first);
				pc.erase(find_if(pc.begin(),pc.end(),comps(request)));
			}
			else break;
		}
		int countn = 0;
		for(vector<int>::iterator it = pn.begin();it != pn.end();it++)
		{
			for(vector<int>::iterator ie = it+1;ie != pn.end();ie++)
			{
                pair<int,int> pt(*it,*ie);
                if((find(pc.begin(),pc.end(),pt) == pc.end()) && (find(pc.begin(),pc.end(),make_pair(pt.second,pt.first)) == pc.end())) countn++;
			}
		}
		cout<<countn<<endl;
	}
}
