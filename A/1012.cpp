//扭曲之作mkII。
//感受我使用稀疏表的怒火吧！

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    int cprog;
    int math;
    int english;
    int average;
} student;

typedef struct {
    int position;
    char subject;
} rankn;

typedef struct {
    vector<rankn> ranks;
} studentrank;

void handler(vector<studentrank>& r,vector<student>& p,const char& subject)
{
    int countn = 1,position = 1,prev = -1;
    auto picker = [&](const char subject,const student a)->int {
            switch(subject)
            {
                case 'A':return a.average;break;
                case 'C':return a.cprog;break;
                case 'M':return a.math;break;
                case 'E':return a.english;break;
            }
            return  -2;
        };
    sort(p.begin(),p.end(),[&](student a,student b)->bool{return picker(subject,a) > picker(subject,b);});
    for_each(p.begin(),p.end(),[&](student s)->void
             {
                 if(prev == -1) prev = picker(subject,s);
                 else if(prev != picker(subject,s))
                 {
                     prev = picker(subject,s);
                     position = countn;
                 }
                 r[s.number].ranks.push_back({position,(subject == 'M' ? 'D' : subject)});
                 countn++;
            });
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<student> p;
    for(int i = 0; i < n; i++)
    {
        int number,cprog,math,english;
        cin>>number>>cprog>>math>>english;
        p.push_back({number,cprog,math,english,round((double)(cprog + math + english) / 3)});
    }
    vector<studentrank> r(1000000);
    handler(r,p,'C');
    handler(r,p,'M');
    handler(r,p,'E');
    handler(r,p,'A');
    for(int i = 0; i < m; i++)
    {
        int request;
        cin>>request;
        if(!r[request].ranks.empty())
        {
            auto it = min_element(r[request].ranks.begin(),r[request].ranks.end(),[&](rankn a,rankn b)->bool {
                    if(a.position != b.position) return a.position < b.position;
                    else return a.subject < b.subject;
                });
            cout<<(*it).position<<" "<<((*it).subject == 'D' ? 'M' : (*it).subject)<<"\n";
        }
        else cout<<"N/A\n";
    }
}
