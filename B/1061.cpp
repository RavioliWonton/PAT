#include <iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int (*pm) = new int[m];bool (*am) = new bool[m];
    for(int i = 0;i < m;i++) cin>>pm[i];
    for(int i = 0;i < m;i++) cin>>am[i];
    for(int i = 0;i < n;i++)
    {
        int grade = 0;
        for(int j = 0;j < m;j++)
        {
            bool temp;
            cin>>temp;
            if(temp == am[j]) grade += pm[j];
        }
        cout<<grade<<endl;
    }
    delete [] pm;delete [] am;
}
