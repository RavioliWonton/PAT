#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int countn = 0;double sum = 0.0;
	for(int i = 0;i < n;i++)
    {
        string temps;
        double tempd;
        cin>>temps;
        bool flag = true;
        try{tempd = stof(temps);}
        catch(invalid_argument e) {flag = false;}
        if(flag)
        {
            stringstream ss;
            ss << temps;
            ss >> tempd;
            ss.clear();
            ss.str("");
            if(tempd >= -1000 && tempd <= 1000)
            {
                if(tempd*100 - (int)(tempd*100) == 0)
                {
                    sum += tempd;
                    countn++;
                }
                else flag = false;
            }
            else flag = false;
        }
        if(!flag) cout<<"ERROR: "<<temps<<" is not a legal number"<<endl;
    }
    cout.setf(ios::fixed);
    if(!countn) cout<<"The average of 0 numbers is Undefined"<<endl;
    else if(countn == 1) cout<<"The average of "<<countn<<" number is "<<setprecision(2)<<sum/countn<<endl;
    else cout<<"The average of "<<countn<<" numbers is "<<setprecision(2)<<sum/countn<<endl;
}
