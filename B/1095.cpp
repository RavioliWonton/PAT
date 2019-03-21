//需要输入时就做处理，否则会超时

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

template<typename T1, typename T2>
bool cmp(const pair<T1, T2>& a, const pair<T1, T2>& b)
{
    if(a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    unordered_map<char, vector<pair<string, int> > > p1;
    unordered_map<int, pair<int, int> > p2;
    unordered_map<int, unordered_map<int, int> > p3;
    for(int i = 0;i < n;i++)
    {
        string adticnum;
        adticnum.resize(13);
        int grade;
        scanf("%s %d",&adticnum[0],&grade);
        p1[adticnum.front()].push_back(pair<string, int>(adticnum,grade));
        p2[stoi(adticnum.substr(1,3))].first++;p2[stoi(adticnum.substr(1,3))].second += grade;
        p3[stoi(adticnum.substr(4,6))][stoi(adticnum.substr(1,3))]++;
    }
    for(int i = 0;i < m;i++)
    {
        int type;
        scanf("%d ",&type);
        printf("Case %d: %d",i + 1,type);
        switch(type)
        {
            case 1:
            {
                char order;
                scanf("%c",&order);
                printf(" %c\n",order);
                if(!p1[order].empty())
                {
                    sort(p1[order].begin(),p1[order].end(),cmp<string,int>);
                    for_each(p1[order].begin(),p1[order].end(),[&](auto a)->void{printf("%s %d\n",a.first.c_str(),a.second);});
                }
                else printf("NA\n");
                break;
            }
            case 2:
            {
                int order;
                scanf("%d",&order);
                printf(" %d\n",order);
                if(p2[order].first) printf("%d %d\n",p2[order].first,p2[order].second);
                else printf("NA\n");
                break;
            }
            case 3:
            {
                int order;
                scanf("%d",&order);
                printf(" %d\n",order);
                if(!p3[order].empty())
                {
                    vector<pair<int,int> > tp(p3[order].begin(),p3[order].end());
                    sort(tp.begin(),tp.end(),cmp<int,int>);
                    for_each(tp.begin(),tp.end(),[&](auto a)->void{printf("%d %d\n",a.first,a.second);});
                }
                else printf("NA\n");
                break;
            }
        }
    }
}
