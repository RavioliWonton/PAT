//要用稀疏表，不然超时。

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> couple(100000);
    for(int i = 0;i < n;i++)
    {
        int bride,bridegroom;
        cin>>bride>>bridegroom;
        couple[bride] = bridegroom;
        couple[bridegroom] = bride;
    }
    vector<int> people,dog;
    int m;
    cin>>m;
    for(int i = 0;i < m;i++)
    {
        int participant;
        cin>>participant;
        people.push_back(participant);
    }
    for(auto it = people.begin();it != people.end();it++)
    {
        if(find(people.begin(),people.end(),couple[*it]) == people.end())
            dog.push_back(*it);
    }
    cout<<dog.size()<<endl;
    if(dog.size())
    {
        sort(dog.begin(),dog.end());
        cout<<setfill('0')<<setw(5)<<dog.front();
        for(auto& people : dog) cout<<" "<<setfill('0')<<setw(5)<<people;
        cout<<endl;
    }
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
