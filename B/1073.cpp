#include <iostream>
#include <iomanip>
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

int main()
{
    int n,m;
    cin>>n>>m;
    vector<question> v;
    for(int i = 0; i < m; i++)
    {
        question temp;
        int number;
        cin>>temp.point>>number>>number;
        temp.answer.resize(number);
        for(int j = 0; j < number; j++) cin>>temp.answer[j];
        sort(temp.answer.begin(),temp.answer.end());
        v.push_back(temp);
    }
    cin.sync();
    vector<wronganswer> w;
    cout.setf(ios::fixed);
    for(int i = 0; i < n; i++)
    {
        string input;
        getline(cin,input);
        vector<question> ans;
        stringstream ss(input);
        char in;
        question tempq;
        for(; ss>>in;)
        {
            if(in == '(') tempq.answer.clear();
            else if(in == ')')
            {
                sort(tempq.answer.begin(),tempq.answer.end());
                ans.push_back(tempq);
            }
            else if(isalpha(in)) tempq.answer.push_back(in);
        }
        double grade = 0;
        for(int j = 0; j < m; j++)
        {
            vector<char> difference(5);
            auto ite = set_symmetric_difference(ans[j].answer.begin(),ans[j].answer.end(),v[j].answer.begin(),v[j].answer.end(),difference.begin());
            difference.resize(ite - difference.begin());
            if(difference.size())
            {
                if(ans[j].answer.size() < v[j].answer.size()) grade += v[j].point / 2;
                for(char& c : difference)
                {
                    auto itt = find_if(w.begin(),w.end(),[&](wronganswer a)->bool{return (a.sequence == j + 1) && (a.option == c);});
                    if(itt != w.end()) (*itt).countn++;
                    else w.push_back({1,j + 1,c});
                }
            }
            else grade += v[j].point;
        }
        cout<<setprecision(1)<<grade<<"\n";
    }
    cout.unsetf(ios::fixed);
    auto f = [&](wronganswer a,wronganswer b)->bool
                    {
                        if(a.countn != b.countn) return a.countn > b.countn;
                        else if(a.sequence != b.sequence) return a.sequence < b.sequence;
                        else return a.option < b.option;
                    };
    sort(w.begin(),w.end(),f);
    if(w.size())
    {
        for(wronganswer &a : w)
        {
            if(a.countn == w.front().countn) cout<<a.countn<<" "<<a.sequence<<"-"<<a.option<<"\n";
            else break;
        }
    }
    else cout<<"Too simple"<<endl;
}
