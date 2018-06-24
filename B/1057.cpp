#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	string a;
    char ch;
	for(;cin.get(ch) && ch != '\n';)
        if(isalpha(ch)) a.push_back(tolower(ch));
	int sum = accumulate(a.begin(),a.end(),0,[&](const int x, const char y)->int{return x + (int)(y - 'a' + 1);}),count0 = 0,count1 = 0;
	for(;sum != 0;)
    {
        if(sum%2 == 1) count1++;
        else count0++;
        sum /= 2;
    }
    cout<<count0<<" "<<count1<<endl;
}
