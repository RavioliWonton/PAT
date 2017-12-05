//是的，我写的代码就是要这么扭曲。

#include <iostream>
#include <limits>
using namespace std;
int main()
{
	int n,stop,maxsum = -1,sum = 0,beginn;
	long start = numeric_limits<int>::max() + 1,maxstart = numeric_limits<int>::max() + 1,maxstop = numeric_limits<int>::max() + 1;
	cin>>n;
	for(int i = 0;i < n;i++)
    {
        cin>>stop;
        if(!i) beginn = stop;
        if(start == numeric_limits<int>::max() + 1) start = stop;
        sum += stop;
        if(sum < 0)
        {
            start = numeric_limits<int>::max() + 1;
            sum = 0;
        }
        else if(sum > maxsum)
        {
            maxstart = start;
            maxstop = stop;
            maxsum = sum;
        }
    }
    cout<<(maxsum < 0 ? 0 : maxsum)<<" "
            <<(maxstart == numeric_limits<int>::max() + 1 ? beginn : maxstart)<<" "
            <<(maxstop == numeric_limits<int>::max() + 1 ? stop : maxstop)<<endl;
}
