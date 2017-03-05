#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct {
    int number;
    int grade;
} Team;

bool cmp(Team a,Team b)
{
    return a.grade > b.grade;
}

int Stoi(string a)
{
    int b= 0;
    for(int i = a.find("-") - 1;i >= 0;i--)
        b += (int)(a[i] - 48)*pow(10,a.find("-") - 1 - i);
    return b;
}

int main()
{
	int n;
	cin>>n;
	Team (*p) = new Team[n];
	int countn = 0;
	for(int i = 0;i < n;i++)
    {
        string c;int a,b;bool flag = true;
        cin>>c>>b;
        a = Stoi(c);
        for(int j = 0;j < countn;j++)
        {
            if(p[j].number == a)
            {
                p[j].grade += b;
                flag = false;
            }
        }
        if(flag)
        {
            p[countn].number = a;
            p[countn].grade = b;
            countn++;
        }
    }
    sort(p,p+countn,cmp);
    cout<<p[0].number<<" "<<p[0].grade<<endl;
    delete [] p;
}
