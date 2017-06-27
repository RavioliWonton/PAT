#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    int result = (a.size() == 1 ? 1 : 0);
    for(auto i = a.begin(); i != a.end()-1; i++)
    {
        //cout<<ceil((double)(a.end() - i)/2)<<"\n";
        for(auto it = i + 1; it != i + ceil((double)(a.end() - i)/2) + 1; it++)
        {
            string temp(i,it);
            reverse(temp.begin(),temp.end());
            if(it - i > 1)
            {
                //cout<<temp<<"\t"<<a.substr(((it - i)% 2 != 0 ? (it - a.begin()) : (it - a.begin() - 1)),(it - i))<<"\t";
                if((temp == a.substr(((it - i)% 2 != 0 ? (it - a.begin()) : (it - a.begin() - 1)),(it - i))) && ((it - i)%2 != 0 ? ((it - i) * 2 - 1) : ((it - i) * 2)) > result)
                    result = ((it - i)%2 != 0 ? ((it - i) * 2) : ((it - i) * 2 - 1));
                //cout<<result<<"\n";
                //cout<<temp<<"\t"<<a.substr(((it - i)% 2 != 0 ? (it - a.begin() - 1) : (it - a.begin())),(it - i))<<"\t";
                if((temp == a.substr(((it - i)% 2 != 0 ? (it - a.begin() - 1) : (it - a.begin())),(it - i))) && ((it - i)%2 != 0 ? ((it - i) * 2 - 1) : ((it - i) * 2)) > result)
                    result = ((it - i)%2 != 0 ? ((it - i) * 2 - 1) : ((it - i) * 2));
                //cout<<result<<"\n";
            }
            else
            {
                //cout<<temp<<"\t"<<a.substr(((it - i)% 2 != 0 ? (it - a.begin()) : (it - a.begin() - 1)),(it - i))<<"\t";
                if((temp == a.substr(((it - i)% 2 != 0 ? (it - a.begin()) : (it - a.begin() - 1)),(it - i))) && ((it - i)%2 != 0 ? ((it - i) * 2 - 1) : ((it - i) * 2)) > result)
                    result = ((it - i)%2 != 0 ? ((it - i) * 2) : ((it - i) * 2 - 1));
                //cout<<result<<"\n";
            }
        }
    }
    cout<<result<<endl;
}
