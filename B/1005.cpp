#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int number;
    bool notchecked;
} number;

int main()
{
    int n;
    cin>>n;
    vector<number> p;
    for(int i = 0;i < n;i++)
    {
        number temp;
        cin>>temp.number;
        temp.notchecked = true;
        p.push_back(temp);
    }
    sort(p.begin(),p.end(),[&](number a,number b){return a.number > b.number;});
    for(number& it : p)
    {
        if(it.notchecked)
        {
            int temp = it.number;
            for(;temp != 1;)
            {
                if(temp % 2) temp = (3*temp+1)/2;
                else temp /= 2;
                auto cmp = [&](number t)->bool {return (temp == t.number);};
                if(find_if(p.begin(),p.end(),cmp) != p.end()) p.at(find_if(p.begin(),p.end(),cmp) - p.begin()).notchecked = false;
            }
        }
    }
    bool flag = true;
    for(number& it : p)
    {
        if(it.notchecked)
        {
            if(flag) {cout<<it.number;flag = false;}
            else cout<<" "<<it.number;
        }
    }
}
