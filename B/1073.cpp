#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    double point;
    vector<char> answer;
} question;

typedef struct {
    int countn;
    int sequence;
    char option;
} wronganswer;

vector<question>& handler(string& input)
{
    vector<question> r;
    auto f = [&](char a)->int{return (int)(a - '0');};
    for(int start = 0,finish = input.find(')');finish < input.size();)
    {
        question temp;
        temp.point = 0;
        stringstream ss(input.substr(start+3,finish-start-3));
        char in;
        for(;ss >> in;) temp.answer.push_back(in);
        sort(temp.answer.begin(),temp.answer.end());
        r.push_back(temp);
        input.erase(start,finish-start);
        start = input.find('(');
        finish = input.find(')');
    }
    return r;
}

int main()
{
	int n,m;
	cin>>n>>m;
	vector<question> v;
	for(int i = 0;i < m;i++)
    {
        question temp;int number;
        cin>>temp.point>>number>>number;
        temp.answer.resize(number);
        for(int j = 0;j < number;j++) cin>>temp.answer[j];
        sort(temp.answer.begin(),temp.answer.end());
        v.push_back(temp);
    }
    vector<wronganswer> w;
    for(int i = 0;i < n;i++)
    {
        string input;
        getline(cin,input);
        vector<question> ans = handler(input);
        double grade = 0;
        for(int j = 0;j < m;j++)
        {
            if(ans[j].answer != v[j].answer)
            {

            }
            else grade += v[j].point;
        }
        cout<<grade<<"\n";
    }
    if(w.size())
        for(wronganswer &a : w) cout<<a.countn<<" "<<a.sequence<<"-"<<a.option<<"\n";
    else cout<<"Too simple"<<endl;
}
