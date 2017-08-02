//四种方法依空间复杂度低（时间复杂度高）——>时间复杂度低（空间复杂度高）顺序排序。
//请自行将最后一个方法改为scanf/printf方式方可通过。
//保留四种方法的意思是抗议这种对时间的变态追求。
//上课的时候说好的空间也要考虑的呢？

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	/*空间复杂度最低
	vector<int> v1,v2;
	for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        auto it = find(v1.begin(),v1.end(),temp);
        if(it != v1.end())
        {
            v2.push_back(*it);
            v1.erase(it);
        }
        else if(!v2.size() || find(v2.begin(),v2.end(),temp) == v2.end()) v1.push_back(temp);
    }
    if(v1.size()) cout<<v1.front()<<endl;
    else cout<<"None"<<endl;
    */
    /*次佳空间复杂度方案
    vector<int> v(n);
    for(int i = 0;i < n;i++) cin>>v[i];
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        if(count(v.begin(),v.end(),v[i]) == 1)
        {
            flag = false;
            cout<<v[i]<<endl;
            break;
        }
    }
    if(flag) cout<<"None"<<endl;
    */
    /*次佳时间复杂度方案
    vector<int> v1,v2;
    for(int i = 0;i < n;i++)
    {
        int temp;
        cin>>temp;
        auto it = find(v1.begin(),v1.end(),temp);
        if(it != v1.end()) v2[(it - v1.begin())]++;
        else
        {
            v1.push_back(temp);
            v2.push_back(1);
        }
    }
    bool flag = true;
    for(int i = 0;i < v2.size();i++)
    {
        if(v2[i] == 1)
        {
            flag = false;
            cout<<v1[i]<<endl;
            break;
        }
    }
    if(flag) cout<<"None"<<endl;
    */
    //时间复杂度最低
    vector<int> v1(n),v2(10001);
    for(int i = 0;i < n;i++)
    {
        cin>>v1[i];
        v2[v1[i]]++;
    }
    bool flag = true;
    for(int i = 0;i < n;i++)
    {
        if(v2[v1[i]] == 1)
        {
            flag = false;
            cout<<v1[i]<<endl;
            break;
        }
    }
    if(flag) cout<<"None"<<endl;
}
