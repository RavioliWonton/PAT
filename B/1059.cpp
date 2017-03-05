//本题不能用iostream，会超时........

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool *createPrime(int N)
{
    bool (*p) = new bool[N+1];
    memset(p,true,sizeof(bool)*(N+1));
    p[0] = p[1] = false;
    for(int i = 2;i < sqrt(N)+1;i++)
    {
        if(p[i])
        {
            for(int j = i;i*j < N+1;j++)
                p[j*i] = false;
        }
    }
    return p;
}

void Find(int N,int *p,bool *q,int r,bool *s)
{
    for(int i = 1;i < N+1;i++)
    {
        if(r == p[i])
        {
            if(!q[i])
            {
                if(s[i])
                {
                    printf("%04d: Minion\n",r);
                    q[i] = true;
                    return ;
                }
                else if(i == 1)
                {
                    printf("%04d: Mystery Award\n",r);
                    q[i] = true;
                    return ;
                }
                else
                {
                    printf("%04d: Chocolate\n",r);
                    q[i] = true;
                    return ;
                }
            }
            else
            {
                printf("%04d: Checked\n",r);
                return ;
            }
        }
    }
    printf("%04d: Are you kidding?\n",r);
}

int main()
{
	int N,M;int r;
	scanf("%d",&N);
    int (*p) = new int[N+1];
    for(int i = 1;i <= N;i++)
        scanf("%d",&p[i]);
    bool (*q) = new bool[N+1];bool (*s) = createPrime(N);
    memset(q,false,sizeof(bool)*(N+1));
    scanf("%d",&M);
    for(int j = 0;j < M;j++)
    {
        scanf("%d",&r);
        Find(N,p,q,r,s);
    }
    delete [] p;delete [] q;delete [] s;
}
