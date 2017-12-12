#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string result;
	auto f = [&](char a)->int{return (a - 'A' + '1');};
	for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            string input;
            cin>>input;
            if(input.back() == 'T') result.push_back(f(input.front()));
        }
    }
    cout<<result<<endl;
}
