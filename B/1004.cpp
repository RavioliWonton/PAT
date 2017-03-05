#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    string number;
    int grade;
};
int main()
{
    int n;Student s,Max,Min;
    cin>>n;
    cin>>Max.name>>Max.number>>Max.grade;
    Min = Max;n--;
    for(;n>0;n--)
    {
        cin>>s.name>>s.number>>s.grade;
        if(s.grade > Max.grade) Max = s;
        if(s.grade < Min.grade) Min = s;
    }
    cout<<Max.name<<" "<<Max.number<<endl<<Min.name<<" "<<Min.number<<endl;
    return 0;
}
/*int main()
{
    int n,i;
    cin>>n;Student s[n],*Min = &s[n-1],*Max = s;
    for(i = 0;i < n;i++)
        cin>>s[i].name>>s[i].number>>s[i].grade;
    for(i = 0;i < n;i++)
    {
        if(Max->grade < s[i].grade) Max = &s[i];
        if(Min->grade > s[i].grade) Min = &s[i];
    }
    cout<<Max->name<<" "<<Max->number<<endl<<Min->name<<" "<<Min->number<<endl;
    return 0;
}
*/
