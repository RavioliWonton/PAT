#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    string name;
    int height;
} people;

bool cmp(people a,people b)
{
    if(a.height != b.height) return a.height > b.height;
    else return a.name < b.name;
}

int main()
{
	int n,k;
	cin>>n>>k;
	int pn = n/k + n - n/k*k;
	people (*p) = new people[n];
    for(int i = 0;i < n;i++)
        cin>>p[i].name>>p[i].height;
    sort(p,p+n,cmp);
    int countn = 0;
    for(int i = 0;i < k;i++)
    {
        if(!i && countn < n)
        {
            bool flag1 = true;
            people (*tp) = new people[n/k + n - n/k*k];
            int flag = (n/k + n - n/k*k)/2;int flagl = flag - 1;int flagr = flag + 1;
            for(int j = 0;j < n/k + n - n/k*k;j++)
            {
                if(countn < n)
                {
                    if(flag1)
                    {
                        tp[flag] = p[countn];
                        flag1 = false;
                        countn++;
                    }
                    else
                    {
                        if(j % 2 == 0 && flagr < n/k + n - n/k*k)
                        {
                            tp[flagr] = p[countn];
                            flagr++;
                            countn++;
                        }
                        else if(j % 2 != 0 && flagl >= 0)
                        {
                            tp[flagl] = p[countn];
                            flagl--;
                            countn++;
                        }
                    }
                }
            }
            bool flag2 = true;
            for(int i = 0;i < n/k + n - n/k*k;i++)
            {
                if(flag2)
                {
                    cout<<tp[i].name;
                    flag2 = false;
                }
                else cout<<" "<<tp[i].name;
            }
            cout<<endl;
            delete [] tp;
        }
        else if(countn < n)
        {
            bool flag1 = true;
            people (*tp) = new people[n/k];
            int flag = (n/k)/2;int flagl = flag - 1;int flagr = flag + 1;
            for(int j = 0;j < n/k;j++)
            {
                if(countn < n)
                {
                    if(flag1)
                    {
                        tp[flag] = p[countn];
                        flag1 = false;
                        countn++;
                    }
                    else
                    {
                        if(j % 2 == 0 && flagr < n/k)
                        {
                            tp[flagr] = p[countn];
                            flagr++;
                            countn++;
                        }
                        else if(j % 2 != 0 && flagl >= 0)
                        {
                            tp[flagl] = p[countn];
                            flagl--;
                            countn++;
                        }
                    }
                }
            }
            bool flag2 = true;
            for(int i = 0;i < n/k;i++)
            {
                if(flag2)
                {
                    cout<<tp[i].name;
                    flag2 = false;
                }
                else cout<<" "<<tp[i].name;
            }
            cout<<endl;
            delete [] tp;
        }
    }
    delete [] p;
}
