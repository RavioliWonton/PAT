//国际惯例，不能用iostream（用了sync_with_stdio(false)和tie(0)没用，咄咄怪事）。
//注释掉的代码是我以为sort超时，自己写的在线计算算法.......

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct {
    int number;
    string name;
// string grade;
    int grade;
} student;

int main()
{
	int n,c;
	scanf("%d%d",&n,&c);
	vector<student> v;
    for(int i = 0;i < n;i++)
    {
        student temp;
        char nam[9];
        scanf("%d%s%d",&(temp.number),nam,&(temp.grade));
        string sname(nam);temp.name = sname;
        v.push_back(temp);
    }
    switch(c)
    {
        case 1:sort(v.begin(),v.end(),[&](student a,student b)->bool{return a.number < b.number;});break;
        case 2:sort(v.begin(),v.end(),[&](student a,student b)->bool{return (a.name != b.name ? a.name < b.name : a.number < b.number);});break;
        case 3:sort(v.begin(),v.end(),[&](student a,student b)->bool{return (a.grade != b.grade ? a.grade < b.grade : a.number < b.number);});break;
    }
/*	vector<int> vn;
	vector<string> cmp;
	for(int i = 0;i < n;i++)
    {
        student temp;
        char nam[9],gra[3];
        scanf("%d%s%s",&(temp.number),nam,gra);
        string sname(nam);temp.name = sname;
        string sgrade(gra);temp.grade = sgrade;
        switch(c)
        {
            case 1:{
                auto low = lower_bound(vn.begin(),vn.end(),temp.number);
                v.insert(v.begin()+(low - vn.begin()),temp);
                vn.insert(low,temp.number);
                break;
            }
            case 2:{
                auto up = upper_bound(cmp.begin(),cmp.end(),temp.name);
                auto low = lower_bound(cmp.begin(),cmp.end(),temp.name);
                if(up == low)
                {
                    v.insert(v.begin()+(low - cmp.begin()),temp);
                    vn.insert(vn.begin()+(low - cmp.begin()),temp.number);
                    cmp.insert(low,temp.name);
                }
                else
                {
                    auto lown = lower_bound(vn.begin()+(low - cmp.begin()),vn.begin()+(up - cmp.begin()),temp.number);
                    v.insert(v.begin()+(lown - vn.begin()),temp);
                    cmp.insert(cmp.begin()+(lown - vn.begin()),temp.name);
                    vn.insert(lown,temp.number);
                }
                break;
            }
            case 3:{
                auto up = upper_bound(cmp.begin(),cmp.end(),temp.grade);
                auto low = lower_bound(cmp.begin(),cmp.end(),temp.grade);
                if(up == low)
                {
                    v.insert(v.begin()+(low - cmp.begin()),temp);
                    vn.insert(vn.begin()+(low - cmp.begin()),temp.number);
                    cmp.insert(low,temp.grade);
                }
                else
                {
                    auto lown = lower_bound(vn.begin()+(low - cmp.begin()),vn.begin()+(up - cmp.begin()),temp.number);
                    v.insert(v.begin()+(lown - vn.begin()),temp);
                    cmp.insert(cmp.begin()+(lown - vn.begin()),temp.grade);
                    vn.insert(lown,temp.number);
                }
                break;
            }
        }
    }*/
    for(student &s : v)
    {
        const char *nam = s.name.c_str();
        printf("%06d %s %d\n",s.number,nam,s.grade);
//     const char *gra = s.grade.c_str();
//     printf("%06d %s %s\n",s.number,nam,gra);
    }
}
