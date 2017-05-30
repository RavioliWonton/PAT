#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
    string name;
    string ID;
    int grade;
} student;

int main()
{
    int n;
    cin>>n;
    vector<student> male,female;
    for(int i = 0;i < n;i++)
    {
        student temp;
        char temps;
        cin>>temp.name>>temps>>temp.ID>>temp.grade;
        if(temps == 'F') female.push_back(temp);
        else male.push_back(temp);
    }
    auto maxfemale = max_element(female.begin(),female.end(),[&](student a,student b)->bool{return a.grade < b.grade;});
    auto minmale = min_element(male.begin(),male.end(),[&](student a,student b)->bool{return a.grade < b.grade;});
    cout<<(female.size() ? ((*maxfemale).name+" "+(*maxfemale).ID) : "Absent")<<"\n"<<(male.size() ? ((*minmale).name+" "+(*minmale).ID) : "Absent")<<"\n"<<((male.size() && female.size()) ? to_string((*maxfemale).grade - (*minmale).grade) : "NA")<<endl;
}
