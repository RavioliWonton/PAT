#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    map<int, string> earthNumtoMarsSingleTable {
    	make_pair(0,"tret"),make_pair(1,"jan"),
    	make_pair(2,"feb"),make_pair(3,"mar"),
    	make_pair(4,"apr"),make_pair(5,"may"),
    	make_pair(6,"jun"),make_pair(7,"jly"),
    	make_pair(8,"aug"),make_pair(9,"sep"),
    	make_pair(10,"oct"),make_pair(11,"nov"),
    	make_pair(12,"dec")},
    	earthNumtoMarsTenTable {
		make_pair(1,"tam"),make_pair(2,"hel"),
		make_pair(3,"maa"),make_pair(4,"huh"),
		make_pair(5,"tou"),make_pair(6,"kes"),
		make_pair(7,"hei"),make_pair(8,"elo"),
		make_pair(9,"syy"),make_pair(10,"lok"),
		make_pair(11,"mer"),make_pair(12,"jou")};
	map<string, int> marsNumtoEarthSingleTable,marsNumtoEarthTenTable;
	for_each(earthNumtoMarsSingleTable.begin(),earthNumtoMarsSingleTable.end(),[&](auto a)->void{marsNumtoEarthSingleTable.insert({a.second,a.first});});
	for_each(earthNumtoMarsTenTable.begin(),earthNumtoMarsTenTable.end(),[&](auto a)->void{marsNumtoEarthSingleTable.insert({a.second,a.first * 13});});
	for_each(earthNumtoMarsTenTable.begin(),earthNumtoMarsTenTable.end(),[&](auto a)->void{marsNumtoEarthTenTable.insert({a.second,a.first});});
    for(int j = 0;j < n;j++)
	{
        getline(cin,s);
        if(isdigit(s.front()))
            cout<<(stoi(s) / 13 ? earthNumtoMarsTenTable[stoi(s) / 13] : earthNumtoMarsSingleTable[stoi(s)])<<(stoi(s) - (stoi(s) / 13 ? stoi(s) / 13 * 13 : stoi(s)) ? " " + earthNumtoMarsSingleTable[(stoi(s) - stoi(s) / 13 * 13)] : "")<<"\n";
        else if(!s.empty())
        {
            if(s.length() <= 4) cout<<marsNumtoEarthSingleTable[s]<<endl;
            else cout<<marsNumtoEarthTenTable[s.substr(0,3)] * 13 + marsNumtoEarthSingleTable[s.substr(4,s.length()-1)]<<endl;
        }
	}
}
