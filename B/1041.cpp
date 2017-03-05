#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string number;
    int test;
    int seat;
} candidate;

int main()
{
	int n,m;
	cin>>n;
    candidate (*p) = new candidate[n];
	for(int i = 0;i < n;i++) cin>>p[i].number>>p[i].test>>p[i].seat;
	cin>>m;
    for(int i = 0;i < m;i++)
    {
        int temp;
        cin>>temp;
        for(int j = 0;j < n;j++)
            if(temp == p[j].test)
                cout<<p[j].number<<" "<<p[j].seat<<endl;
    }
    delete [] p;
}
