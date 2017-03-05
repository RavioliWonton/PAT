//要用稀疏表，不然超时。

#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
using namespace std;



int main()
{
    int couple[100000],n;
    cin>>n;
    for(int i = 0;i < n;i++)
    {
        int temp1,temp2;
        cin>>temp1>>temp2;
        couple[temp1] = temp2;
        couple[temp2] = temp1;
    }
    int (*dog) = new int[n];
    int m,countn;countn = 0;
    cin>>m;
    int (*people) = new int[m];
    for(int i = 0;i < m;i++) cin>>people[i];
    for(int i = 0;i < m;i++)
    {
        if(!couple[people[i]])
        {
            dog[countn] = people[i];
            countn++;
        }
        else
        {
            bool flag = false;
            for(int j = 0;j < m;j++)
                if(people[j] == couple[people[i]]) {flag = true;break;}
            if(!flag)
            {
                dog[countn] = people[i];
                countn++;
            }
        }
    }
    cout<<countn<<endl;
    if(countn)
    {
        sort(dog,dog+countn,less<int>());
        cout<<setfill('0')<<setw(5)<<dog[0];
        for(int i = 1; i < countn; i++) cout<<" "<<setfill('0')<<setw(5)<<dog[i];
        cout<<endl;
    }
    delete [] dog;
}

/*

非稀疏表做法

typedef struct
{
    int bride;
    int bridegroom;
    bool found;
} couple;

typedef struct
{
    int number;
    bool maritalstatus;
} people;

int main()
{
    int n;
    cin>>n;
    couple (*p1) = new couple[n];
    for(int i = 0; i < n; i++)
    {
        cin>>p1[i].bride>>p1[i].bridegroom;
        p1[i].found = false;
    }
    int m;
    cin>>m;
    people (*p2) = new people[m];
    for(int i = 0; i < m; i++)
    {
        cin>>p2[i].number;
        p2[i].maritalstatus = false;
    }
    for(int i = 0; i < m; i++)
    {
        if(!p2[i].maritalstatus)
        {
            for(int j = 0; j < n; j++)
            {
                if((p2[i].number == p1[j].bride) && !p1[j].found)
                {
                    for(int k = i+1; k < m; k++)
                        if((p2[k].number == p1[j].bridegroom) && !p2[k].maritalstatus)
                            p2[i].maritalstatus = p2[k].maritalstatus = p1[j].found = true;
                }
                else if((p2[i].number == p1[j].bridegroom) && !p1[j].found)
                {
                    for(int k = i+1; k < m; k++)
                        if((p2[k].number == p1[j].bride) && !p2[k].maritalstatus)
                            p2[i].maritalstatus = p2[k].maritalstatus = p1[j].found = true;
                }
            }
        }
    }
    delete [] p1;
    int (*dog) = new int[m];
    int countn = 0;
    for(int i = 0; i < m; i++)
    {
        if(!p2[i].maritalstatus)
        {
            dog[countn] = p2[i].number;
            countn++;
        }
    }
    delete [] p2;
    cout<<countn<<endl;
    if(countn)
    {
        sort(dog,dog+countn,less<int>());
        cout<<setfill('0')<<setw(5)<<dog[0];
        for(int i = 1; i < countn; i++) cout<<" "<<setfill('0')<<setw(5)<<dog[i];
    }
    delete [] dog;
}
*/
