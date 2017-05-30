#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef struct {
    int next;
    bool checked;
} node;

int main()
{
	int first,second,n;
	cin>>first>>second>>n;
	vector<node> v(100000);
	for(int i = 0;i < n;i++)
    {
        int tempi;char tempc;
        cin>>tempi;
        cin>>tempc>>v[tempi].next;
        v[tempi].checked = false;
    }
    int visit = first;
    for(;visit != -1;)
    {
        v[visit].checked = true;
        visit = v[visit].next;
    }
    visit = second;
    for(;visit != -1;)
    {
        if(v[visit].checked) break;
         visit = v[visit].next;
    }
    if(visit != -1) cout<<setw(5)<<setfill('0')<<visit<<endl;
    else cout<<visit<<endl;
}
