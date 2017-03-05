#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    char g;
    int countn;
} gesture;

class people
{
    public:
    int victory;
    int lose;
    int tie;
    gesture gest[3];
    people();
};

people::people() {victory = lose = tie = 0;gest[0].g = 'C';gest[1].g = 'J';gest[2].g = 'B';gest[0].countn = gest[1].countn = gest[2].countn = 0;}

bool cmp(gesture a,gesture b)
{
    if(a.countn != b.countn)
        return a.countn > b.countn;
    else return a.g < b.g;
}

int Judge(char a,char b)
{
    if(a == 'C')
    {
        if(b == 'J') return 1;
        else if(b == 'C') return 2;
        else return 3;
    }
    else if(a == 'J')
    {
        if(b == 'J') return 4;
        else if(b == 'C') return 5;
        else return 6;
    }
    else
    {
        if(b == 'J') return 7;
        else if(b == 'C') return 8;
        else return 9;
    }
}

int main()
{
	int n;
	cin>>n;
	people a = people();people b = people();
	for(int i = 0;i < n;i++)
    {
        char tempa,tempb;
        cin>>tempa>>tempb;
        switch(Judge(tempa,tempb))
        {
            case 1:a.victory++;b.lose++;a.gest[0].countn++;break;
            case 2:a.tie++;b.tie++;break;
            case 3:a.lose++;b.victory++;b.gest[2].countn++;break;
            case 4:a.tie++;b.tie++;break;
            case 5:a.lose++;b.victory++;b.gest[0].countn++;break;
            case 6:a.victory++;b.lose++;a.gest[1].countn++;break;
            case 7:a.lose++;b.victory++;b.gest[1].countn++;break;
            case 8:a.victory++;b.lose++;a.gest[2].countn++;break;
            case 9:a.tie++;b.tie++;break;
        }
    }
    cout<<a.victory<<" "<<a.tie<<" "<<a.lose<<endl;
    cout<<b.victory<<" "<<b.tie<<" "<<b.lose<<endl;
    sort(a.gest,a.gest+3,cmp);sort(b.gest,b.gest+3,cmp);
    cout<<a.gest[0].g<<" "<<b.gest[0].g<<endl;
}
