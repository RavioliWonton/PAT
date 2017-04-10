//本题不能用iostream，会超时......

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    int moral;
    int intelligence;
} Student;

bool cmp(Student& a,Student& b)
{
    if((a.moral + a.intelligence) != (b.moral + b.intelligence))
        return (a.intelligence + a.moral) > (b.intelligence + b.moral);
    else if(a.moral != b.moral)
        return a.moral > b.moral;
    else return a.number < b.number;
}

void printStudent(vector<Student>& p)
{
    sort(p.begin(),p.end(),cmp);
    for(auto& s : p) printf("%d %d %d\n",s.number,s.moral,s.intelligence);
}

int main()
{
	int n,l,h,countn = 0;
	scanf("%d %d %d",&n,&l,&h);
	vector<Student> p1,p2,p3,p4;
    for(int i = 0;i < n;i++)
    {
        int tn,td,tc;
        scanf("%d %d %d",&tn,&td,&tc);
        if(td >= l && tc >= l)
        {
            countn++;
            if(td >= h && tc >= h)
            {
                Student temp;
                temp.number = tn;
                temp.moral = td;
                temp.intelligence = tc;
                p1.push_back(temp);
            }
            else if(td >= h)
            {
                Student temp;
                temp.number = tn;
                temp.moral = td;
                temp.intelligence = tc;
                p2.push_back(temp);
            }
            else if(td >= tc)
            {
                Student temp;
                temp.number = tn;
                temp.moral = td;
                temp.intelligence = tc;
                p3.push_back(temp);
            }
            else
            {
                Student temp;
                temp.number = tn;
                temp.moral = td;
                temp.intelligence = tc;
                p4.push_back(temp);
            }
        }
    }
    printf("%d\n",countn);
    printStudent(p1);
    printStudent(p2);
    printStudent(p3);
    printStudent(p4);
}
