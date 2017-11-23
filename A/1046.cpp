#include <iostream>
#include <vector>
#include <algorithm>
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
        distance.push_back(circumference);
        circumference += temp;
    }
	cin>>m;
	for(int i = 0;i < m;i++)
    {
        int start,stop;
        cin>>start>>stop;
        int length = distance[max(start,stop) - 1] - distance[min(start,stop) - 1];
        cout<<min(length,circumference - length)<<endl;
    }
}
