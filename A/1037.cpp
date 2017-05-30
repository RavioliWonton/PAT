//你们火星商店脑子有点问题的！

#include <iostream>
#include <functional>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	int nc,np,countpn,countnn;
	countpn = countnn = 0;
	deque<int> vc,vp;
	cin>>nc;
	for(int i = 0;i < nc;i++)
    {
        int temp;
        cin>>temp;
        if(temp < 0) {vc.push_back(temp);countnn++;}
        else {vc.push_front(temp);countpn++;}
    }
    sort(vc.begin(),vc.begin()+countpn,greater<int>());
    sort(vc.end()-countnn,vc.end(),greater<int>());
    countpn = countnn = 0;
    cin>>np;
	for(int i = 0;i < np;i++)
    {
        int temp;
        cin>>temp;
        if(temp < 0) {vp.push_back(temp);countnn++;}
        else {vp.push_front(temp);countpn++;}
    }
    sort(vp.begin(),vp.begin()+countpn,greater<int>());
    sort(vp.end()-countnn,vp.end(),greater<int>());
    long long money = 0;
    bool flag = false;
    for(auto itc = vc.begin(),itp = vp.begin();itc != vc.end() && itp != vp.end();itc++,itp++)
    {
        if((*itc)*(*itp) > 0) money += (*itc)*(*itp);
        else {flag = true;break;}
    }
    if(flag)
    {
        for(auto itrc = vc.rbegin(),itrp = vp.rbegin();itrc != vc.rend() && itrp != vp.rend();itrc++,itrp++)
        {
            if((*itrc)*(*itrp) > 0) money += (*itrc)*(*itrp);
            else break;
        }
    }
    cout<<money<<endl;
}
