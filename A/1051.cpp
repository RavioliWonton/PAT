#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	for(int i = 0;i < k;i++)
    {
        stack<int> s;
        bool flag = true;
        int number = 1;
        for(int j = 0;j < n;j++)
        {
            int input;
            cin>>input;
            if(s.size() && s.top() == input) s.pop();
            else
            {
                bool over = false;
                for(;!s.size() || s.top() != input;)
                {
                    if(s.size() < m) s.push(number);
                    else {over = true;break;}
                    if(number <= n) number++;
                    else {over = true;break;}
                }
                if(over) flag = false;
                else s.pop();
            }
        }
        cout<<(flag ? "YES" : "NO")<<endl;
    }
}
