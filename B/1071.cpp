//两个空格！

#include <iostream>
using namespace std;
int main()
{
    int t,k;
    cin>>t>>k;
    for(int i = 0; i < k; i++)
    {
        int n1,b,t1,n2;
        cin>>n1>>b>>t1>>n2;
        if(t1 > t) cout<<"Not enough tokens.  Total = "<<t<<"."<<endl;
        else
        {
            if((b && n1 < n2) || (!b && n1 > n2))
            {
                    t += t1;
                    cout<<"Win "<<t1<<"!  Total = "<<t<<"."<<endl;
            }
            else
            {
                t -= t1;
                cout<<"Lose "<<t1<<".  Total = "<<t<<"."<<endl;
                if(!t)
                {
                    cout<<"Game Over."<<endl;
                    break;
                }
            }
        }
    }
}
