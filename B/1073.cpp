#include <iostream>
using namespace std;

typedef struct {
    int point;
    vector<char> answer;
} question;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<question> v;
	for(int i = 0;i < m;i++)
    {
        question temp;int number;
        cin>>temp.point>>number>>number;
        temp.answer.resize(number);
        for(int j = 0;j < number;j++) cin>>temp.answer[j];
        v.push_back(temp);
    }
    for(int i = 0;i < n;i++)
    {
        string input;
        getline(cin,input);
    }
}
