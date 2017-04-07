#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
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
        if(count(temps.begin(),temps.end(),'.') > 1) flag = false;
        try{tempd = stod(temps);}
        catch(invalid_argument e) {flag = false;}
        if((temps.end() - find(temps.begin(),temps.end(),'.')) > 3) flag = false;
        else if((!isdigit(temps.front()) && temps.front() != '-') || (temps.front() == '-' && !isdigit(*(temps.begin()+1)))) flag = false;
        if(flag)
        {
            tempd = stod(temps);
            if(tempd >= -1000.00 && tempd <= 1000.00)
            {
                sum += tempd;
                countn++;
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
