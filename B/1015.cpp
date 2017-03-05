//本题不能用iostream，会超时......

#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    int moral;
    int intelligence;
} Student;

bool cmp(Student a,Student b)
{
    if((a.moral + a.intelligence) != (b.moral + b.intelligence))
        return (a.intelligence + a.moral) > (b.intelligence + b.moral);
    else if(a.moral != b.moral)
        return a.moral > b.moral;
    else return a.number < b.number;
}

void printStudent(Student *p,int n)
{
    sort(p,p+n,cmp);
    for(int i = 0;i < n;i++)
        printf("%d %d %d\n",p[i].number,p[i].moral,p[i].intelligence);
}

int main()
{
	int n,l,h,tn,td,tc,countn,p1n,p2n,p3n,p4n;countn = p1n = p2n = p3n = p4n =  0;
	scanf("%d %d %d",&n,&l,&h);
	Student (*p1) = new Student[n];Student (*p2) = new Student[n];Student (*p3) = new Student[n];Student (*p4) = new Student[n];
    for(int i = 0;i < n;i++)
    {
        scanf("%d %d %d",&tn,&td,&tc);
        if(td >= l && tc >= l)
        {
            countn++;
            if(td >= h && tc >= h)
            {
                p1[p1n].number = tn;
                p1[p1n].moral = td;
                p1[p1n].intelligence = tc;
                p1n++;
            }
            else if(td >= h)
            {
                p2[p2n].number = tn;
                p2[p2n].moral = td;
                p2[p2n].intelligence = tc;
                p2n++;
            }
            else if(td >= tc)
            {
                p3[p3n].number = tn;
                p3[p3n].moral = td;
                p3[p3n].intelligence = tc;
                p3n++;
            }
            else
            {
                p4[p4n].number = tn;
                p4[p4n].moral = td;
                p4[p4n].intelligence = tc;
                p4n++;
            }
        }
    }
    printf("%d\n",countn);
    printStudent(p1,p1n);
    printStudent(p2,p2n);
    printStudent(p3,p3n);
    printStudent(p4,p4n);
    delete [] p1;delete [] p2;delete [] p3;delete [] p4;
}
