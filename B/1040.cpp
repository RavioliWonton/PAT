#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int (*p1) = new int[s.length()];int (*p2) = new int[s.length()];int (*p3) = new int[s.length()];
	long countn = 0;long countnP = 0;long countnA = 0;long countnT = 0;
	for(int i = 0;i < s.length();i++)
    {
        int mark1 = 0;int mark2 = 0;
        if(s[i] == 'P') {p1[countnP] = mark1 = i;countnP++;}
        else if(s[i] == 'A' && i > mark1) {p2[countnA] = mark2 = i;countnA++;}
        else if(s[i] == 'T' && i > mark2) {p3[countnT] = i;countnT++;}
    }
    for(int i = 0;i < countnP;i++)
    {
        bool flag = true;
        for(int j = 0;j < countnA;j++)
            if(p1[i] < p2[j] && flag)
                for(int k = 0;k < countnT;k++)
                    if(p2[j] < p3[k]) {countn++;flag = false;break;}
    }
    delete [] p1;delete [] p2;delete [] p3;
    cout<<countn % 1000000007<<endl;
}
