//注释掉的代码可实现运用当前系统时间来判断的功能，题目又没说清楚指定2014/09/06......

#include <iostream>
//#include <sstream>
//#include <ctime>
#include <string>
using namespace std;

typedef struct {
    string name;
    string birth;
} Person;

/*int convert(string a)
{
    stringstream ss;
    ss << a;
    int i;
    ss >> i;
    ss.clear();
    ss.str("");
    return i;
}

bool judge(string a)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(convert(a.substr(0,4)) > ltm->tm_year + 1900 || convert(a.substr(0,4)) < ltm->tm_year + 1700) return false;
    else if((convert(a.substr(0,4)) == ltm->tm_year + 1900 && convert(a.substr(a.find('/') + 1,2)) > ltm->tm_mon + 1) || (convert(a.substr(0,4)) == ltm->tm_year + 1700 && convert(a.substr(a.find('/') + 1,2)) < ltm->tm_mon + 1)) return false;
    else if((convert(a.substr(0,4)) == ltm->tm_year + 1900 && convert(a.substr(a.find('/') + 1,2)) == ltm->tm_mon + 1 && convert(a.substr(a.rfind('/') + 1,2)) > ltm->tm_mday) || (convert(a.substr(0,4)) == ltm->tm_year + 1700 && convert(a.substr(a.find('/') + 1,2)) == ltm->tm_mon + 1 && convert(a.substr(a.rfind('/') + 1,2)) < ltm->tm_mday)) return false;
    else return true;
}*/

int main()
{
    int n;
    cin>>n;
    Person (*p) = new Person[n];Person maxs,mins;
    maxs.birth = "2014/09/07";mins.birth = "1814/09/05";
    int countn = 0;
    for(int i = 0;i < n;i++)
    {
        string tn,tb;
        cin>>tn>>tb;
        if(tb <= "2014/09/06" && tb >= "1814/09/06")
        {
            p[countn].name = tn;
            p[countn].birth = tb;
            maxs = (tb < maxs.birth ? p[countn] : maxs);
            mins = (tb > mins.birth ? p[countn] : mins);
            countn++;
        }
    }
    if(countn) cout<<countn<<" "<<maxs.name<<" "<<mins.name<<endl;
    else cout<<countn<<endl;
    delete [] p;
}
