#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    string ID_number;
    string Sign_in_time;
    string Sign_out_time;
} ID;

bool signin(ID a,ID b) {return a.Sign_in_time < b.Sign_in_time;}
bool signout(ID a,ID b) {return a.Sign_out_time < b.Sign_out_time;}

int main()
{
    int n;
    cin>>n;
    ID (*p) = new ID[n];
    for(int i = 0;i < n;i++)
        cin>>p[i].ID_number>>p[i].Sign_in_time>>p[i].Sign_out_time;
    cout<<(*min_element(p,p+n,signin)).ID_number<<" "<<(*max_element(p,p+n,signout)).ID_number<<endl;
}
