//你们火星商店脑子有点问题的！

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int nc,np;
	vector<int> vc,vp;
	cin>>nc;
	for(int i = 0;i < nc;i++)
    {
        int temp;
        cin>>temp;
        vc.push_back(temp);
    }
    sort(vc.begin(),vc.end());
    cin>>np;
	for(int i = 0;i < np;i++)
    {
        int temp;
        cin>>temp;
        vp.push_back(temp);
    }
    sort(vp.begin(),vp.end());
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
