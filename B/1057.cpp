#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int countalpha(string a)
{
    int sum = 0;
    for(int i = 0;i < a.length();i++)
        if((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z')) sum += (int)(tolower(a[i]) - 'a' + 1);
    return sum;
}

int main()
{
	string a;
	getline(cin,a);
	int sum = countalpha(a);
	int count1 = 0;int count0 = 0;
	for(;sum != 0;)
    {
        if(sum%2 == 1) count1++;
        else count0++;
        sum /= 2;
    }
    cout<<count0<<" "<<count1<<endl;
}
