#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,countn = 0;
    cin>>n;
    double sum = 0.0;
    for(int i = 0;i < n;i++)
    {
        string temps;
        cin>>temps;
        bool flag = true;
        if(count(temps.begin(),temps.end(),'.') > 1) flag = false;
        if((distance(find(temps.begin(),temps.end(),'.'),temps.end())) > 3) flag = false;
        else if((!isdigit(temps.front()) && temps.front() != '-') || (temps.front() == '-' && !isdigit(*(temps.begin()+1)))) flag = false;
        if(flag)
        {
        	try {
				double tempd = stod(temps);
				if(tempd >= -1000.00 && tempd <= 1000.00)
				{
					sum += tempd;
					countn++;
				}
				else flag = false;
        	}
        	catch(invalid_argument e) {flag = false;}
        }
        if(!flag) cout<<"ERROR: "<<temps<<" is not a legal number\n";
    }
    cout.setf(ios::fixed);
    if(!countn) cout<<"The average of 0 numbers is Undefined\n";
    else if(countn == 1) cout<<"The average of "<<countn<<" number is "<<setprecision(2)<<sum/countn<<"\n";
    else cout<<"The average of "<<countn<<" numbers is "<<setprecision(2)<<sum/countn<<"\n";
}
