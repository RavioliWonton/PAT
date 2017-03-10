#include <iostream>
using namespace std;

typedef struct {
    int value;
    bool duplication;
} pixel;

bool compare(int &a,int &b,int &threshold)
{
    if(((a > b) ? a : b) - ((a < b) ? a : b) > threshold) return true;
    else return false;
}

int main()
{
    int rown,arrayn,threshold;
    cin>>arrayn>>rown>>threshold;
    pixel (*p) = new pixel[arrayn*rown];
    for(int i = 0; i < arrayn*rown; i++)
    {
        cin>>p[i].value;
        p[i].duplication = true;
        for(int j = 0; j < i; j++)
            if(p[j].value == p[i].value) {p[i].duplication = p[j].duplication = false;break;}
    }
    bool flag = true;int answer = -1;
    for(int i = 0; i < arrayn*rown; i++)
    {
        if(p[i].duplication)
        {
            if(!(i/arrayn))
            {
                if(!(i%arrayn))
                {
                    if(compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else if(i%arrayn == arrayn - 1)
                {
                    if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else
                {
                    if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
            }
            else if(i/arrayn == rown - 1)
            {
                if(i%arrayn == arrayn - 1)
                {
                    if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else if(!(i%arrayn))
                {
                    if(compare(p[i+1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else
                {
                    if(compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
            }
            else
            {
                if(!(i%arrayn))
                {
                    if(compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else if(i%arrayn == arrayn - 1)
                {
                    if(compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
                else
                {
                    if(compare(p[i-arrayn-1].value,p[i].value,threshold) && compare(p[i-arrayn].value,p[i].value,threshold) && compare(p[i-arrayn+1].value,p[i].value,threshold) && compare(p[i-1].value,p[i].value,threshold) && compare(p[i+1].value,p[i].value,threshold) && compare(p[i+arrayn-1].value,p[i].value,threshold) && compare(p[i+arrayn].value,p[i].value,threshold) && compare(p[i+arrayn+1].value,p[i].value,threshold))
                    {
                        if(answer == -1) answer = i;
                        else {flag = false;break;}
                    }
                }
            }
        }
    }
    if(answer == -1) cout<<"Not Exist"<<endl;
    else if(answer != -1 && flag) cout<<"("<<answer % arrayn +1<<", "<<answer / arrayn + 1<<"): "<<p[answer].value<<endl;
    else if(!flag) cout<<"Not Unique"<<endl;
    delete [] p;
}
