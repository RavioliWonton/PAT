#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    int grade;
    set<char> truth;
    int error;
} topic;

struct topicCompare {
	bool operator() (const topic& a, const topic& b) const {
		if(a.error != b.error) return a.error > b.error;
		else return a.number < b.number;
	}
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<topic> p;
    for(int i = 0;i < m;i++)
    {
    	int grade, option, truthn;
    	set<char> truth;
        cin>>grade>>option>>truthn;
        for(int j = 0;j < truthn;j++)
        {
            char temp;
            cin>>temp;
            truth.insert(temp);
        }
        p.push_back({i + 1, grade, truth, 0});
    }
    for(int i = 0;i < n;i++)
    {
        int grade = 0;
        for(auto& a : p)
        {
            int option;char temp;
            cin>>temp>>option;
            set<char> answer;
            for(;(cin>>temp) && (temp != ')');) answer.insert(temp);
            if(answer == a.truth) grade += a.grade;
            else a.error++;
        }
        cout<<grade<<endl;
    }
    set<topic, topicCompare> result(p.begin(),p.end());
    if(!(*result.begin()).error) cout<<"Too simple"<<endl;
    else
    {
    	cout<<(*result.begin()).error;
        for(auto& a : result)
        {
            if(a.error == (*result.begin()).error) cout<<" "<<a.number;
            else break;
        }
    }
}
