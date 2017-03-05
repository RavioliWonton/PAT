#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n1,n2,m1,m2,k;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	bool (*p) = new bool[k+1];memset(p,true,sizeof(bool)*(k+1));p[0] = p[1] = false;
	for(int i = 1;i <= k;i++)
    {
        if(p[i])
        {
            for(int j = i;j * i <= k;j++)
                p[j * i] = false;
        }
    }
    int first = 1;int last = k;bool flag1 = true;bool flag2 = false;
    for(int i = 1;i <= k;i++)
    {
        if(flag1)
        {
            if((double)((double)i/(double)k) > ((double)((double)n1/(double)m1) < (double)((double)n2/(double)m2) ? (double)((double)n1/(double)m1) : (double)((double)n2/(double)m2)))
            {
                first = i - 1;
                flag1 = false;
                flag2 = true;
            }
        }
        else if(flag2)
        {
            if((double)((double)i/(double)k) > ((double)((double)n1/(double)m1) > (double)((double)n2/(double)m2) ? (double)((double)n1/(double)m1) : (double)((double)n2/(double)m2)))
            {
                last  = i - 1;
                flag2 = false;
            }
        }
    }
    bool flag3 = true;
    for(int i = first;i <= last;i++)
    {
        if(p[i])
        {
            if(flag3) {cout<<i<<"/"<<k;flag3 = false;}
            else cout<<" "<<i<<"/"<<k;
        }
    }
    delete [] p;
}
/*
#include <algorithm>
int gcd(int a,int b)
{
    if(b == 0) return a;
    else return gcd(b,a % b);
}

int lcm(int a,int b) {return a*b/gcd(a,b);}

int main()
{
    int n1,n2,m1,m2,k;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
	const int g = lcm(m1,lcm(m2,k));
    int (*np) = new int[max(n1*(g/m1),n2*(g/m2)) + 1];int countn = 0;
    for(int i = min(n1*(g/m1),n2*(g/m2));i <= max(n1*(g/m1),n2*(g/m2));i += (g/k))
    {
        if(gcd(i/(g/k),k) == 1)
        {
            np[countn] = i;
            countn++;
        }
    }
    sort(np,np+countn);
    cout<<np[0]/(g/k)<<"/"<<k;
    for(int i = 1;i < countn;i++) cout<<" "<<np[i]/(g/k)<<"/"<<k;
    cout<<endl;
    delete [] np;
}*/
