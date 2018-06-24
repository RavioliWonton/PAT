#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a,b;
	auto ctoi = [&](const char c)->int{return (c - '0');};
	auto itoc = [&](const int i)->char{return (i + '0');};
	cin>>a>>b;
    (a.size() < b.size() ? a : b).insert(0,(a.size() > b.size() ? a : b).size() - (a.size() < b.size() ? a : b).size(),'0');
    for(auto it = b.rbegin();it != b.rend();it++)
    {
        if((distance(b.rbegin(),it) + 1) % 2 != 0)
        {
            switch((ctoi(*next(a.rbegin(),distance(b.rbegin(),it))) + ctoi(*it)) % 13)
            {
                case 12:(*it) = 'K';break;
                case 11:(*it) = 'Q';break;
                case 10:(*it) = 'J';break;
                default:(*it) = itoc((ctoi(*next(a.rbegin(),distance(b.rbegin(),it))) + ctoi(*it)) % 13);break;
            }
        }
        else
        {
            if(ctoi(*it) - ctoi(*next(a.rbegin(),distance(b.rbegin(),it))) < 0) (*it) = itoc(10 + ctoi(*it) - ctoi(*next(a.rbegin(),distance(b.rbegin(),it))));
            else (*it) = itoc(ctoi(*it) - ctoi(*next(a.rbegin(),distance(b.rbegin(),it))));
        }
    }
    cout<<b<<endl;
}
