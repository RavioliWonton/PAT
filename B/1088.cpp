#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int m,x,y;
	cin>>m>>x>>y;
	bool flag = false;
	for(int a = 99;a >= 10;a--)
    {
        string as = to_string(a);
        if(abs(abs(a - stoi(string(as.rbegin(),as.rend()))) - x*(stod(string(as.rbegin(),as.rend())) / y)) < 0.000001)
        {
            flag = true;
            cout<<a<<" "
                <<(m < a ? "Cong" : (m > a ? "Gai" : "Ping"))<<" "
                <<(m < stoi(string(as.rbegin(),as.rend())) ? "Cong" : (m > stoi(string(as.rbegin(),as.rend())) ? "Gai" : "Ping"))<<" "
                <<(m < (stod(string(as.rbegin(),as.rend())) / y) ? "Cong" : (m > (stod(string(as.rbegin(),as.rend())) / y) ? "Gai" : "Ping"))
                <<endl;
            break;
        }
    }
    if(!flag) cout<<"No Solution"<<endl;
}
