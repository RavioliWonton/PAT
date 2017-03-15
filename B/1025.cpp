//根据国际惯例，本题只能用稀疏表.......
//还有，你他妈没说过结点有可能不在链表上的啊！

#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef struct {
	int data;
	int next;
} LNode;

int main()
{
	int first,n,k;
    cin>>first>>n>>k;
    LNode p[100000];
    for(int i = 0;i < n;i++)
	{
		int temp;
		cin>>temp;
		cin>>p[temp].data>>p[temp].next;
	}
	int (*ap) = new int[n];
	int (*dp) = new int[n];
	int flag = first;int countn = 0;
	for(int i = 0;i < k;i++)
	{
		if(flag != -1)
		{
			ap[i] = flag;
			dp[i] = p[flag].data;
			flag = p[flag].next;
			countn++;
		}
		else break;
	}
	reverse(ap,ap+countn);
	reverse(dp,dp+countn);
	for(int i = k;i < n;i++)
	{
		if(flag != -1)
		{
			ap[i] = flag;
			dp[i] = p[flag].data;
			flag = p[flag].next;
			countn++;
		}
		else break;
	}
	cout.fill('0');
    for(int i = 0;i < countn;i++)
	{
		cout<<setw(5)<<ap[i]<<" ";
		cout<<dp[i]<<" ";
		if(i != countn - 1) cout<<setw(5)<<ap[i+1]<<"\n";
		else cout<<"-1\n";
	}
	delete [] ap;delete [] dp;
}
