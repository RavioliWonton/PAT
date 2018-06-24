#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
    string name;
    int height;
} people;

void process(const vector<people>& p,const int& length,int& countn,const int& n)
{
    vector<people> tp(length,{"",0});
    bool flag1 = true;
    int flagl = length/2 - 1,flagr = length/2 + 1;
    for(int j = 0; j < length; j++)
    {
        if(countn < n)
        {
            if(flag1)
            {
                *next(tp.begin(),length / 2) = *next(p.begin(),countn);
                flag1 = false;
                countn++;
            }
            else if(!(j % 2) && flagr < length)
            {
                *next(tp.begin(),flagr) = *next(p.begin(),countn);
                flagr++;
                countn++;
            }
            else if(j % 2 && flagl >= 0)
            {
                *next(tp.begin(),flagl) = *next(p.begin(),countn);
                flagl--;
                countn++;
            }
        }
        else break;
    }
    for(auto it = tp.begin();it != tp.end();it++)
		cout<<(it != tp.begin() ? " " : "")<<(*it).name;
    cout<<endl;
}

int main()
{
    int n,k,countn = 0;
    cin>>n>>k;
    vector<people> p;
    for(int i = 0; i < n; i++)
    {
        string name;
        int height;
        cin>>name>>height;
        p.push_back({name, height});
    }
    sort(p.begin(),p.end(),[&](people a,people b)->bool{if(a.height != b.height) return a.height > b.height; else return a.name < b.name;});
    for(int i = 0; i < k; i++)
    {
        if(countn < n) process(p,(i ? n/k : n/k + n - n/k*k),countn,n);
        else break;
    }
}
