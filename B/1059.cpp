//本题不能用iostream，会超时........

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

void createPrime(int& N, vector<bool>& p)
{
	for(auto it = p.begin();it != next(p.begin(),sqrt(N) + 1);it++)
	{
		if(distance(p.begin(),it) < 2) (*it) = false;
		else if(*it)
		{
			for(int i = (int)distance(p.begin(),it);i * distance(p.begin(),it) < N + 1;i++)
				*next(p.begin(),distance(p.begin(),it) * i) = false;
		}
	}
}

void Find(int& N,vector<int>& p,vector<bool>& q,int& r,vector<bool>& s)
{
	for(auto it = p.begin();it != p.end();it++)
	{
		if(r == (*it))
		{
			if(!*next(q.begin(),distance(p.begin(),it)))
			{
				if(*next(s.begin(),distance(p.begin(),it) + 1))
				{
					printf("%04d: Minion\n",r);
                    *next(q.begin(),distance(p.begin(),it)) = true;
                    return ;
				}
				else if(!distance(p.begin(),it))
				{
					printf("%04d: Mystery Award\n",r);
					*next(q.begin(),distance(p.begin(),it)) = true;
					return ;
				}
				else
				{
					printf("%04d: Chocolate\n",r);
					*next(q.begin(),distance(p.begin(),it)) = true;
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
    vector<int> p(N);
    for(int i = 0;i < N;i++) scanf("%d",&p[i]);
    vector<bool> q(N,false),s(N+1,true);
    createPrime(N,s);
    scanf("%d",&M);
    for(int j = 0;j < M;j++)
    {
        scanf("%d",&r);
        Find(N,p,q,r,s);
    }
}
