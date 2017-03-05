#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    bool notchecked;
} number;

bool cmp(number a,number b) {return a.number > b.number;}

int main()
{
    int n;
    cin>>n;
    number (*p) = new number[n];
    for(int i = 0;i < n;i++) {cin>>p[i].number;p[i].notchecked = true;}
    sort(p,p+n,cmp);
    for(int i = 0;i < n;i++)
    {
        if(p[i].notchecked)
        {
            int temp = p[i].number;
            for(;temp != 1;)
            {
                if(temp % 2) temp = (3*temp+1)/2;
                else temp /= 2;
                for(int j = 0;j < n;j ++)
                    if(temp == p[j].number) p[j].notchecked = false;
            }
        }
    }
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        if(p[i].notchecked)
        {
            if(flag) {cout<<p[i].number;flag = false;}
            else cout<<" "<<p[i].number;
        }
    }
    delete [] p;
}
