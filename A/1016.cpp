#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct {
	int hour;
	int minute;
	int second;
	bool status;
} detailt;

typedef struct {
	int month;
	vector<detailt> detail;
} recordt;

typedef struct {
	string name;
	vector<recordt> record;
} bill;

struct compn {
	compn(string const& s) : _s(s) {}
	bool operator() (bill const& p) {return p.name == _s;}
	string _s;
};

struct compm {
	compm(int const& i) : _i(i) {}
	bool operator() (recordt const& p) {return p.month == _i;}
	int _i;
};

bool cmpp(bill a,bill b) {return a.name < b.name;}
bool cmpr(recordt a,recordt b) {return a.month < b.month;}
bool cmpd(detailt a,detailt b)
{
	if(a.status == b.status)
	{
		if(a.hour != b.hour) return a.hour < b.hour;
		else if(a.minute != b.minute) return a.minute < b.minute;
		else return a.second < b.second;
	}
	else return a.status;
}

int main()
{
	int charge[24];
	for(int i = 0;i < 24;i++) cin>>charge[i];
	int n;
	cin>>n;
	vector<bill> p;
	for(int i = 0;i < n;i++)
	{
		string name,time,status;
		cin>>name>>time>>status;
		if(find_if(p.begin(),p.end(),compn(name)) != p.end())
		{
			if(find_if((*find_if(p.begin(),p.end(),compn(name))).record.begin(),(*find_if(p.begin(),p.end(),compn(name))).record.end(),compm(stoi(time.substr(0,2)))) != (*find_if(p.begin(),p.end(),compn(name))).record.end())
			{
				detailt temp;
				temp.hour = stoi(time.substr(3,2));
				temp.minute = stoi(time.substr(6,2));
				temp.second = stoi(time.substr(9,2));
				temp.status = (status == "on-line" ? true : false);
				(*find_if((*find_if(p.begin(),p.end(),compn(name))).record.begin(),(*find_if(p.begin(),p.end(),compn(name))).record.end(),compm(stoi(time.substr(0,2))))).detail.push_back(temp);
			}
			else
			{
				recordt temp1;
				temp1.month = stoi(time.substr(0,2));
				detailt temp2;
				temp2.hour = stoi(time.substr(3,2));
				temp2.minute = stoi(time.substr(6,2));
				temp2.second = stoi(time.substr(9,2));
				temp2.status = (status == "on-line" ? true : false);
				temp1.detail.push_back(temp2);
				(*find_if(p.begin(),p.end(),compn(name))).record.push_back(temp1);
			}
		}
		else
		{
			bill temp1;
			temp1.name = name;
			recordt temp2;
			temp2.month = stoi(time.substr(0,2));
			detailt temp3;
			temp3.hour = stoi(time.substr(3,2));
			temp3.minute = stoi(time.substr(6,2));
			temp3.second = stoi(time.substr(9,2));
			temp3.status = (status == "on-line" ? true : false);
			temp2.detail.push_back(temp3);
			temp1.record.push_back(temp2);
			p.push_back(temp1);
		}
	}
    sort(p.begin(),p.end(),cmpp);
    for(auto x : p)
	{
		sort(x.record.begin(),x.record.end(),cmpr);
		for(auto y : x.record)
		{
			sort(y.detail.begin(),y.detail.end(),cmpd);
			double cost = 0;
            for(auto it = y.detail.begin()+1;it != y.detail.end();it++)
			{
				if(((*it).status && (*(it-1)).status) || !((*it).status || (*(it-1)).status)) y.detail.erase(it-1);
			}
		}
	}
}
