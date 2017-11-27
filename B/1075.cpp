//本题的坑：
//1.稀疏表，国际惯例，不说了；
//2.给的节点不见得在链表上，这个跟B级1025一样的，也不说了；
//3.可能没有小于0的的节点，同样也有可能没有小于K和大于K的节点；
//4.甚至K本身也有可能不在链表上的；
//5.当然以上两条不会同时满足（因为说了保证链表非空）。

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int key;
    int value;
} node;

int main()
{
	int start,n,k;
	cin>>start>>n>>k;
	vector<node> input(100000),result,lesszero,lessk,morek;
	for(int i = 0;i < n;i++)
    {
        int key,value,next;
        cin>>key>>value>>next;
        input[key] = {next,value};
    }
    int coda = start;
    for(;coda != -1;)
    {
        if(input[coda].value < 0) lesszero.push_back({coda,input[coda].value});
        else if(input[coda].value <= k) lessk.push_back({coda,input[coda].value});
        else if(input[coda].value > k) morek.push_back({coda,input[coda].value});
        coda = input[coda].key;
    }
    result.insert(result.end(),lesszero.begin(),lesszero.end());
    result.insert(result.end(),lessk.begin(),lessk.end());
    result.insert(result.end(),morek.begin(),morek.end());
    for(auto it = result.begin();it != result.end();it++)
    {
        cout<<setw(5)<<setfill('0')<<(*it).key<<" ";
        cout<<(*it).value<<" ";
        if(it != result.end() - 1) cout<<setw(5)<<setfill('0')<<(*(it + 1)).key<<endl;
        else cout<<"-1"<<endl;
    }
}
