#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef struct {
	string ID;
	string title;
	string author;
	vector<string> keyword;
	string publisher;
	int pubyear;
} book;

int main()
{
	int n;
	cin>>n;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	vector<book> v (n);
	for(int i = 0;i < n;i++)
	{
		book tempb;
		getline(cin,tempb.ID);
		getline(cin,tempb.title);
		getline(cin,tempb.author);
		string temps;
		getline(cin,temps);
		istringstream is(temps);
        for(;is >> temps;) tempb.keyword.push_back(temps);
		getline(cin,tempb.publisher);
		cin>>tempb.pubyear;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		v.push_back(tempb);
	}
	cin>>n;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
    for(int i = 0;i < n;i++)
	{
		vector<string> result;
        string temp;
        getline(cin,temp);
        cout<<temp<<endl;
        switch(stoi(temp.substr(0,1)))
        {
			case 1:{for(book& b : v){if(b.title == temp.substr(3)) result.push_back(b.ID);}break;}
			case 2:{for(book& b : v){if(b.author == temp.substr(3)) result.push_back(b.ID);}break;}
			case 3:{for(book& b : v){if(find(b.keyword.begin(),b.keyword.end(),temp.substr(3)) != b.keyword.end()) result.push_back(b.ID);}break;}
			case 4:{for(book& b : v){if(b.publisher == temp.substr(3)) result.push_back(b.ID);}break;}
			case 5:{for(book& b : v){if(b.pubyear == stoi(temp.substr(3))) result.push_back(b.ID);}break;}
        }
        sort(result.begin(),result.end());
        if(result.size()) for_each(result.begin(),result.end(),[&](string ID)-> void {cout<<ID<<"\n";});
        else cout<<"Not Found"<<endl;
	}
}
