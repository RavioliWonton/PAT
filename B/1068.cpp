#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    int value;
    bool duplication;
} pixel;

int main()
{
    int rown,arrayn,threshold;
    cin>>arrayn>>rown>>threshold;
    vector<pixel> p;
    for(int i = 0; i < arrayn*rown; i++)
    {
        int value;
        cin>>value;
        auto it = find_if(p.begin(),p.end(),[&](pixel a)->bool{return a.value == value;});
        if(it != p.end()) (*it).duplication = false;
        p.push_back({value,(it == p.end())});
    }
    bool flag = true;int answer = -1;
    auto compare = [&](int a,int b,int threshold)->bool{return (((a > b) ? a : b) - ((a < b) ? a : b) > threshold);};
    for(int i = 0; i < arrayn*rown; i++)
    {
        bool judge = false;
        if(p[i].duplication)
        {
            if(!(i/arrayn))
            {
                if(!(i%arrayn) && (compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))) judge = true;
                else if((i%arrayn == arrayn - 1) && (compare(p[i-1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold))) judge = true;
                else if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold)) judge = true;
            }
            else if(i/arrayn == rown - 1)
            {
                if((i%arrayn == arrayn - 1) && (compare(p[i-1].value,p[i].value,threshold) && compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold))) judge = true;
                else if(!(i%arrayn) && (compare(p[i+1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold))) judge = true;
                else if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold)) judge = true;
            }
            else
            {
                if(!(i%arrayn) && (compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))) judge = true;
                else if((i%arrayn == arrayn - 1) && (compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold))) judge = true;
                else if(compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold) && compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold)) judge = true;
                }
            }
        if(judge)
        {
            if(answer == -1) answer = i;
            else {flag = false;break;}
        }
    }
    if(answer == -1) cout<<"Not Exist"<<endl;
    else if(!flag) cout<<"Not Unique"<<endl;
    else cout<<"("<<answer % arrayn +1<<", "<<answer / arrayn + 1<<"): "<<p[answer].value<<endl;
}
