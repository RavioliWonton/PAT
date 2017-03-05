#include <iostream>
#include <string>
using namespace std;

typedef struct {
    char name;
    int number;
    bool found;
} pearl;

int Initial(pearl *p,string a)
{
    int countn = 0;
    for(int i = 0;i < a.length();i++)
    {
        bool flag = true;
        for(int j = 0;j < countn;j++)
        {
            if(p[j].name == a[i])
            {
                p[j].number++;
                flag = false;
            }
        }
        if(flag)
        {
            p[countn].name = a[i];
            p[countn].number = 1;
            p[countn].found = false;
            countn++;
        }
    }
    return countn;
}

void judge(pearl *p,pearl *q,int countn1,int countn2)
{
    int spare = 0;int lack = 0;bool flag = false;
    for(int i = 0;i < countn2;i++)
    {
        for(int j = 0;j < countn1;j++)
        {
            if(p[j].name == q[i].name)
            {
                if(p[j].number > q[i].number)
                {
                    lack += p[j].number - q[i].number;
                    flag = q[i].found = p[j].found = true;
                }
                else if(!flag)
                {
                    spare += q[i].number - p[j].number;
                    q[i].found = p[j].found = true;
                }
                else
                    q[i].found = p[j].found = true;
            }
        }
        if(!q[i].found)
            spare += q[i].number;
    }
    for(int i = 0;i < countn1;i++)
    {
        if(!p[i].found)
        {
            flag = true;
            lack += p[i].number;
        }
    }
    if(!flag)
        cout<<"Yes "<<spare<<endl;
    else cout<<"No "<<lack<<endl;
}

int main()
{
    string a,b;
    cin>>b>>a;
    pearl (*p) = new pearl[a.length()];pearl (*q) = new pearl[b.length()];
    int countn1 = Initial(p,a);int countn2 = Initial(q,b);
    judge(p,q,countn1,countn2);
    delete [] p;delete [] q;
}
