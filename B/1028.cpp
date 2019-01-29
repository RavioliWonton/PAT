//注释掉的代码可实现运用当前系统时间来判断的功能，题目又没说清楚指定2014/09/06......

#include <iostream>
//#include <ctime>
//#include <string>
#include <set>
using namespace std;

/*bool judge(string a)
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if(stoi(a.substr(0,4)) > ltm->tm_year + 1900 || stoi(a.substr(0,4)) < ltm->tm_year + 1700) return false;
    else if((stoi(a.substr(0,4)) == ltm->tm_year + 1900 && stoi(a.substr(a.find('/') + 1,2)) > ltm->tm_mon + 1) || (stoi(a.substr(0,4)) == ltm->tm_year + 1700 && stoi(a.substr(a.find('/') + 1,2)) < ltm->tm_mon + 1)) return false;
    else if((stoi(a.substr(0,4)) == ltm->tm_year + 1900 && stoi(a.substr(a.find('/') + 1,2)) == ltm->tm_mon + 1 && stoi(a.substr(a.rfind('/') + 1,2)) > ltm->tm_mday) || (stoi(a.substr(0,4)) == ltm->tm_year + 1700 && stoi(a.substr(a.find('/') + 1,2)) == ltm->tm_mon + 1 && stoi(a.substr(a.rfind('/') + 1,2)) < ltm->tm_mday)) return false;
    else return true;
}*/

int main()
{
    int n;
    cin>>n;
    set<pair<string,string> > p;
    for(int i = 0;i < n;i++)
    {
        string tn,tb;
        cin>>tn>>tb;
        if(tb <= "2014/09/06" && tb >= "1814/09/06") p.insert(make_pair(tb,tn));
    }
    cout<<p.size();
    if(p.size()) cout<<" "<<(*p.begin()).second<<" "<<(*prev(p.end())).second<<endl;
}
