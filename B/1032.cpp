#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int (*p) = new int[100001];
    memset(p,0,sizeof(int)*100001);
    int n;
    cin>>n;
    int maxn = 0;
    for(int i = 0;i < n;i++)
    {
        int number,grade;
        cin>>number>>grade;
        p[number] += grade;
        if(p[number] > p[maxn]) maxn = number;
    }
    cout<<maxn<<" "<<p[maxn]<<endl;
    delete [] p;
}

/*本题不能用下面的做法，会超时......
#include <algorithm>

typedef struct {
    int number;
    int grade;
} school;

bool cmp(school a,school b)
{
    return a.grade > b.grade;
}

int main()
{
	int n;
	cin>>n;
	school (*p) = new school[n];
	int countn = 0;
	for(int i = 0;i < n;i++)
    {
        int number,grade;bool flag = false;
        cin>>number>>grade;
        for(int j = 0;j < countn;j++)
        {
            if(number == p[j].number)
            {
                p[j].grade += grade;
                flag = true;
            }
        }
        if(!flag)
        {
            p[countn].number = number;
            p[countn].grade = grade;
            countn++;
        }
    }
    sort(p,p+countn,cmp);
    cout<<p[0].number<<" "<<p[0].grade<<endl;
    delete [] p;
}*/
