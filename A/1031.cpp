#include <iostream>
using namespace std;
int main()
{
	string input;
	cin>>input;
	int is = input.size();
	int n = (is + 2)/3;
	for(int i = 0;i < n - 1;i++)
    {
        cout<<input.front();
        input.erase(0,1);
        for(int j = 0;j < (is - 2*n);j++) cout<<" ";
        cout<<input.back()<<"\n";
        input.pop_back();
    }
    cout<<input<<endl;
}
