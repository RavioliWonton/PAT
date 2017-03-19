#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

typedef struct {
	char situation;
	double number;
} odds;

bool cmp(odds a,odds b) {return a.number < b.number;}

int main()
{
	double sum = 1.0;
	for(int i = 0;i < 3;i++)
	{
		odds odd[3];
		odd[0].situation = 'W';odd[1].situation = 'T';odd[2].situation = 'L';
		cin>>odd[0].number>>odd[1].number>>odd[2].number;
		cout<<(*max_element(odd,odd+3,cmp)).situation<<" ";
		sum *= (*max_element(odd,odd+3,cmp)).number;
	}
	sum *= 0.65;sum--;sum *= 200;
	sum = round(sum);sum /= 100;
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<sum<<endl;
}
