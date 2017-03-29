#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    int grade;
    int option;
    int truthn;
    string truth;
    int error;
} topic;

bool cmp(topic a,topic b)
{
    if(a.error != b.error) return a.error > b.error;
    else return a.number < b.number;
}

int main()
{
    int n,m;
    cin>>n>>m;
    topic (*p) = new topic[m];
    for(int i = 0;i < m;i++)
    {
        p[i].number = i + 1;
        cin>>p[i].grade>>p[i].option>>p[i].truthn;
        for(int j = 0;j < p[i].truthn;j++)
        {
            char temp;
            cin>>temp;
            p[i].truth.push_back(temp);
        }
        p[i].error = 0;
    }
    for(int i = 0;i < n;i++)
    {
        int grade = 0;
        for(int j = 0;j < m;j++)
        {
            int option;char temp;
            cin>>temp>>option;
            string answer;
            for(;(cin>>temp) && (temp != ')');) answer.push_back(temp);
            sort(answer.begin(),answer.end());
            if(answer == p[j].truth) grade += p[j].grade;
            else p[j].error++;
        }
        cout<<grade<<endl;
    }
    sort(p,p+m,cmp);
    if(!p[0].error) cout<<"Too simple"<<endl;
    else
    {
        cout<<p[0].error;
        for(int i = 0;i < m;i++)
        {
            if(p[i].error == p[0].error) cout<<" "<<p[i].number;
            else break;
        }
    }
}
