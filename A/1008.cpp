#include <iostream>
using namespace std;
int main()
{
    int floor = 0;int time = 0;
    int n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int request;
        cin>>request;
        if(request > floor) time += (request-floor)*6 + 5;
        else time += (floor-request)*4 + 5;
        floor = request;
    }
    cout<<time<<endl;
}
