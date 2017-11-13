#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n,m,circumference = 0;
	cin>>n;
	vector<int> distance;
	for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        circumference += temp;
        distance.push_back(temp);
    }
	cin>>m;
	for(int i = 0;i < m;i++)
    {
        int start,stop,length = 0;
        cin>>start>>stop;
        for(int j = min(start,stop) - 1;j < max(start,stop) - 1;j++) length += distance[j];
        cout<<min(length,circumference - length)<<endl;
    }
}
