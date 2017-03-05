#include <iostream>
using namespace std;
int main()
{
    int factor,index;
    cin>>factor>>index;
    if(index != 0)
    {
        factor *= index;
        index--;
        cout<<factor<<" "<<index;
    }
    else cout<<0<<" "<<0;
	for(;cin>>factor>>index;)
    {
        if(index != 0)
        {
            factor *= index;
            index--;
            cout<<" "<<factor<<" "<<index;
        }
    }
    cout<<endl;
}
