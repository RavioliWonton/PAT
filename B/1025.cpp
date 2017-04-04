//根据国际惯例，本题只能用稀疏表.......
//还有，你他妈没说过结点有可能不在链表上的啊！

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef struct
{
    int data;
    int next;
} LNode;

int main()
{
    int flag,n,k;
    cin>>flag>>n>>k;
    LNode p[100000];
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin>>temp;
        cin>>p[temp].data>>p[temp].next;
    }
    if(flag != -1)
    {
    	int (*ap) = new int[n];
	int (*dp) = new int[n];
	int begin = 0;int end = 0;
        for(int i = 0; i < n/k; i++)
        {
            if(flag != -1)
            {
                bool stop = false;
                for(int j = begin; j < begin+k; j++)
                {
                    if(flag != -1)
                    {
                        ap[j] = flag;
                        dp[j] = p[flag].data;
                        flag = p[flag].next;
                        end++;
                    }
                    else {stop = true;break;}
                 }
                if(!stop)
                {
                    reverse(ap+begin,ap+end);
                    reverse(dp+begin,dp+end);
                    begin = end;
                }
            }
            else break;
        }
        for(int i = end; i < n; i++)
        {
            if(flag != -1)
            {
                ap[i] = flag;
                dp[i] = p[flag].data;
                flag = p[flag].next;
                end++;
            }
            else break;
        }
        cout.fill('0');
        for(int i = 0; i < end; i++)
        {
            cout<<setw(5)<<ap[i]<<" ";
            cout<<dp[i]<<" ";
            if(i != end - 1) cout<<setw(5)<<ap[i+1]<<"\n";
            else cout<<"-1\n";
        }
        delete [] ap;delete [] dp;
    }
    else cout<<"-1\n";
}
