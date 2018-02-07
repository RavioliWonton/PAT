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
    vector<people> tp(length);
    bool flag1 = true;
    int flagl = length/2 - 1,flagr = length/2 + 1;
    for(int j = 0; j < length; j++)
    {
        if(countn < n)
        {
            if(flag1)
            {
                tp[length/2] = p[countn];
                flag1 = false;
                countn++;
            }
            else if(!(j % 2) && flagr < length)
            {
                tp[flagr] = p[countn];
                flagr++;
                countn++;
            }
            else if(j % 2 && flagl >= 0)
            {
                tp[flagl] = p[countn];
                flagl--;
                countn++;
            }
        }
        else break;
    }
    for(int i = 0; i < tp.size(); i++) cout<<(i ? " " : "")<<tp[i].name;
    cout<<endl;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<people> p(n);
    for(int i = 0; i < n; i++) cin>>p[i].name>>p[i].height;
    sort(p.begin(),p.end(),[&](people a,people b)->bool{if(a.height != b.height) return a.height > b.height; else return a.name < b.name;});
    int countn = 0;
    for(int i = 0; i < k; i++)
    {
        if(countn < n) process(p,i ? n/k : n/k + n - n/k*k,countn,n);
        else break;
    }
}
