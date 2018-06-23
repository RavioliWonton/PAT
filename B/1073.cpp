//还有最后那个点……

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef struct {
    int point;
    set<char> answer;
} question;

typedef struct {
    int countn;
    int sequence;
    char option;
} wronganswers;

typedef struct {
	int sequence;
    char option;
} wronganswer;

struct wronganswersCompare {
	bool operator() (const wronganswers& a, const wronganswers& b) const {
		if(a.countn != b.countn) return a.countn > b.countn;
		else if(a.sequence != b.sequence) return a.sequence < b.sequence;
		else return a.option < b.option;
	}
};

struct wronganswerCompare {
	bool operator() (const wronganswer& a, const wronganswer& b) const {
		if(a.sequence != b.sequence) return a.sequence < b.sequence;
		else return a.option < b.option;
	}
};

int main()
{
    int n,m;
    cin>>n>>m;
    map<wronganswer, int, wronganswerCompare> w;
    cout.setf(ios::fixed);
    cout.precision(1);
    for(int i = 0; i < m + n; i++)
    {
    	vector<question> v;
        set<char> answer;
        int point,number;
        cin>>point>>number>>number;
        for(int j = 0; j < number; j++)
		{
			char ans;
			cin>>ans;
			answer.insert(ans);
		}
        v.push_back({point, answer});
        double grade = 0.0;
        for(auto it = v.begin();it != v.end();it++)
        {
        	int option;char temp;
            cin>>temp>>option;
            set<char> answer;
            for(;(cin>>temp) && (temp != ')');) answer.insert(temp);
            vector<char> difference(5);
            auto ite = set_symmetric_difference(answer.begin(),answer.end(),(*it).answer.begin(),(*it).answer.end(),difference.begin());
            difference.resize(ite - difference.begin());
            if(difference.size())
            {
                if(answer.size() < (*it).answer.size()) grade += (double)(*it).point / 2.0;
                for(char& c : difference) w[{(int)distance(v.begin(), it) + 1, c}]++;
            }
            else grade += (*it).point;
        }
        cout<<grade<<"\n";
    }
    set<wronganswers, wronganswersCompare> result;
    for_each(w.begin(),w.end(),[&](auto a)->void{result.insert({a.second, a.first.sequence, a.first.option});});
    if(result.size())
    {
        for(auto &a : result)
        {
            if(a.countn == (*(result.begin())).countn) cout<<a.countn<<" "<<a.sequence<<"-"<<a.option<<"\n";
            else break;
        }
    }
    else cout<<"Too simple"<<endl;
}
