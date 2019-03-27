#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef struct {
    int victory;
    int lose;
    int tie;
    map<char,int> gest;
} people;

auto Judge = [&](auto a,auto b)->int
{
    switch (a)
    {
        case 'C':
        {
            switch (b)
            {
                case 'J': return 1;
                case 'C': return 2;
                case 'B': return 3;
            }
        }
        case 'J':
        {
            switch (b)
            {
                case 'J': return 4;
                case 'C': return 5;
                case 'B': return 6;
            }
        }
        case 'B':
        {
            switch (b)
            {
                case 'J': return 7;
                case 'C': return 8;
                case 'B': return 9;
            }
        }
    }
    return 0;
};

int main()
{
	int n;
	cin>>n;
	people a {0,0,0,{{'C',0},{'J',0},{'B',0}}},b {0,0,0,{{'C',0},{'J',0},{'B',0}}};
	for(int i = 0;i < n;i++)
    {
        char tempa,tempb;
        cin>>tempa>>tempb;
        switch(Judge(tempa,tempb))
        {
            case 1:a.victory++;b.lose++;a.gest['C']++;break;
            case 2:a.tie++;b.tie++;break;
            case 3:a.lose++;b.victory++;b.gest['B']++;break;
            case 4:a.tie++;b.tie++;break;
            case 5:a.lose++;b.victory++;b.gest['C']++;break;
            case 6:a.victory++;b.lose++;a.gest['J']++;break;
            case 7:a.lose++;b.victory++;b.gest['J']++;break;
            case 8:a.victory++;b.lose++;a.gest['B']++;break;
            case 9:a.tie++;b.tie++;break;
        }
    }
    cout<<a.victory<<" "<<a.tie<<" "<<a.lose<<endl;
    cout<<b.victory<<" "<<b.tie<<" "<<b.lose<<endl;
    auto cmp = [&](auto a,auto b)->bool{if(a.second == b.second) return a.first < b.first;else return a.second > b.second;};
    set<pair<char, int>,decltype(cmp)> agest(a.gest.begin(),a.gest.end(),cmp), bgest(b.gest.begin(),b.gest.end(),cmp);
    cout<<(*(agest.begin())).first<<" "<<(*(bgest.begin())).first<<endl;
}
