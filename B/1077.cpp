#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0;i < n;i++)
    {
        double result = 0.0;
        int teacher,maxstudent = -1,minstudent = m + 1,countn = 0;
        cin>>teacher;
        for(int j = 0;j < n- 1;j++)
        {
            int student;
            cin>>student;
            if(student >= 0 && student <= m)
            {
                countn++;
                result += student;
                if(student > maxstudent) maxstudent = student;
                if(student < minstudent) minstudent = student;
            }
        }
        cout<<round(((result - maxstudent - minstudent) / (countn - 2) + teacher) / 2)<<endl;
    }
}
