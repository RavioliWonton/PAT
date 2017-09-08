#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

typedef struct {
    int begin;
    int end;
} result;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    vector<result> r;
    int min_difference = numeric_limits<int>::max();
    for(int begin = 0,end = 0,sum = v.front(); begin < n;)
    {
        if(sum >= m)
        {
            if(sum - m <= min_difference)
            {
                if(sum - m < min_difference)
                {
                    min_difference = sum - m;
                    r.clear();
                }
                result temp;
                temp.begin = begin;
                temp.end = end;
                r.push_back(temp);
            }
            begin++;
            end = begin;
            sum = v[begin];
        }
        else if(end < n)
        {
            end++;
            sum += v[end];
        }
        else break;
    }
    for_each(r.begin(),r.end(),[&](result a)->void{cout<<a.begin + 1<<"-"<<a.end + 1<<endl;});
}
