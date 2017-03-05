#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
    char chr;
    int num;
} alphabet;

bool cmp(alphabet a,alphabet b)
{
    if(a.num == b.num) return a.chr < b.chr;
    else return a.num > b.num;
}

int judge(char a)
{
    if(a >= 65 && a <= 90) return a-65;
    else if(a >= 97 && a <= 122) return a-97;
    else return -1;
}

int main()
{
	string a;
	getline(cin,a);
	alphabet (*p) = new alphabet[26];
	for(int i = 0;i < 26;i++)
    {
        p[i].chr = (char)(i + 97);
        p[i].num = 0;
    }
	for(int i = 0;i < a.length();i++)
        if(judge(a[i]) != -1)
            p[judge(a[i])].num++;
    sort(p,p+26,cmp);
    cout<<p[0].chr<<" "<<p[0].num<<endl;
    delete [] p;
}
