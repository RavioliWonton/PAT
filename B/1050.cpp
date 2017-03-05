#include <iostream>
#include <functional>
#include <algorithm>
#include <cstring>
using namespace std;

int cmp(const void *a,const void *b)
{
     return *(int*)b-*(int*)a;
}

int getwidth(int n)
{
    int mini = n;int width = 1;
    for(int i = 2;i < n-1;i++)
    {
        if(!(n % i) && (n/i > i ? n/i : i) - (n/i < i ? n/i : i) < mini)
        {
            width = (n/i > i ? n/i : i);
            mini = width - (n/i < i ? n/i : i);
        }
    }
    return width;
}

int main()
{
	int n;
	cin>>n;
	int (*p) = new int[n];
    for(int i = 0;i < n;i++) cin>>p[i];
    sort(p,p+n,greater_equal<int>());
    int width = getwidth(n);
    if(width == 1)
    {
        for(int i = 0;i < n;i++) cout<<p[i]<<endl;
        delete [] p;
    }
    else
    {
        int length = n / width;
        int (**o) = new int*[width];
        for(int i = 0;i < width;i++) o[i] = new int[length];
        int rowflag1 = 0;int rowflag2 = width - 1;int arrayflag1 = 0;int arrayflag2 = length - 1;int flag = 0;
        for(;flag < n;)
        {
            if(arrayflag1 != arrayflag2 && flag < n)
            {
                for(int i = arrayflag1;i <= arrayflag2;i++) {o[rowflag1][i] = p[flag];flag++;}
                rowflag1++;
            }
            if(rowflag1 != rowflag2 && flag < n)
            {
                for(int i = rowflag1;i <= rowflag2;i++) {o[i][arrayflag2] = p[flag];flag++;}
                arrayflag2--;
            }
            if(arrayflag1 != arrayflag2 && flag < n)
            {
                for(int i = arrayflag2;i >= arrayflag1;i--) {o[rowflag2][i] = p[flag];flag++;}
                rowflag2--;
            }
            if(rowflag1 != rowflag2 && flag < n)
            {
                for(int i = rowflag2;i >= rowflag1;i--) {o[i][arrayflag1] = p[flag];flag++;}
                arrayflag1++;
            }
        }
        delete [] p;
        for(int i = 0;i < width;i++)
        {
            cout<<o[i][0];
            for(int j = 1;j < length;j++) cout<<" "<<o[i][j];
            cout<<endl;
            delete [] o[i];
        }
        delete [] o;
	}
}
