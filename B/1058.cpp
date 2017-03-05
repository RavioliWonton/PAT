#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
using namespace std;

typedef struct {
    int number;
    int grade;
    int option;
    int trueon;
    int error;
    char trueo[5];
} topic;

typedef struct {
    int trueon;
    char trueo[5];
} answer;

int stoi(char c) {return (int)(c - 48);}

bool cmp(topic a,topic b) {return a.error > b.error;}

int getScore(string a,topic *p,int m)
{
    answer (*ap) = new answer[m+1];int countn = 1;
    for(int i = 0;i < a.length();)
    {
        if(a[i] == '(')
        {
            ap[countn].trueon = stoi(a[i+1]);
            for(int j = i + 3;j < a.length();)
            {
                if(a[j] == ')')
                {
                    string trueo = "";
                    trueo += a.substr(i+3,j-i-3);
                    int countn2 = 0;
                    for(int l = 0;i < trueo.length();l++)
                    {
                        if(isalpha(trueo[l]))
                        {
                            ap[countn].trueo[countn2] = trueo[i];
                            countn2++;
                        }
                    }
                    for(int k = 0;i < ap[countn].trueon;k++) cout<<ap[countn].trueo[k]<<endl;
                    i = j+1;
                    break;
                }
                else j++;
            }
            countn++;
        }
        else i++;
    }
    int sum = 0;int flag = 0;
    for(int i = 1;i < m+1;i++)
    {
        if(ap[i].trueon == p[i].trueon)
        {
            for(int j = 0;j < ap[i].trueon;j++)
            {
                cout<<"Now check student answer "<<ap[i].trueo[j]<<endl;
                for(int k = 0;k < p[i].trueon;k++)
                {
                    cout<<"Now check answer "<<p[i].trueo[k]<<endl;
                    if(p[i].trueo[k] == ap[i].trueo[j])
                    {
                        flag++;
                        cout<<"Checked! flag = "<<flag<<endl;
                        break;
                    }
                }
            }
            if(flag == p[i].trueon) sum += p[i].grade;
            else p[i].error++;
        }
        else p[i].error++;
    }
    delete [] ap;
    return sum;
}


int main()
{
	int n,m;
	cin>>n>>m;
    topic (*p) = new topic[m+1];
    for(int i = 1;i < m+1;i++)
    {
        cin>>p[i].grade>>p[i].option>>p[i].trueon;
        cin.ignore();
        for(int j = 0;j < p[i].trueon;j++) cin>>p[i].trueo[j];
        p[i].number = i;
        p[i].error = 0;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i = 0;i < n;i++)
    {
        string a;
        getline(cin,a);
        cout<<getScore(a,p,m)<<endl;
    }
    sort(p+1,p+m+1,cmp);
    int flag = 1;
    for(int i = 1;i < m+1;i++)
    {
        if(p[i].error == p[i+1].error)
            flag++;
        else break;
    }
    if(p[1].error == 0) cout<<"Too simple";
    else
    {
        cout<<p[1].error<<" "<<p[1].number;
        for(int i = 2;i <= flag;i++)
            cout<<" "<<p[i].number;
    }
    cout<<endl;
    delete [] p;
}
