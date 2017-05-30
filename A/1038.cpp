#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<string> v;
	for(int i = 0;i < n;i++)
    {
        int tempi;
        cin>>tempi;
        v.push_back(to_string(tempi));
    }
    sort(v.begin(),v.end(),[&](string a,string b)->bool
         {
             if(a.front() != b.front()) return a.front() < b.front();
             else if(*(a.begin()+1) != *(b.begin()+1)) return *(a.begin()+1) < *(b.begin()+1);
             else if(*(a.begin()+2) != *(b.begin()+2)) return *(a.begin()+2) < *(b.begin()+2);
             else if(*(a.begin()+3) != *(b.begin()+3)) return *(a.begin()+3) < *(b.begin()+3);
             else if(*(a.begin()+4) != *(b.begin()+4)) return *(a.begin()+4) < *(b.begin()+4);
             else if(*(a.begin()+5) != *(b.begin()+5)) return *(a.begin()+5) < *(b.begin()+5);
             else if(*(a.begin()+6) != *(b.begin()+6)) return *(a.begin()+6) < *(b.begin()+6);
             else return *(a.begin()+7) < *(b.begin()+7);
         });
    for_each(v.begin(),v.end(),[&](string s)->void{cout<<stoi(s);});
    cout<<endl;
}
