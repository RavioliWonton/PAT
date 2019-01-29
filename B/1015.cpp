//本题不能用iostream，会超时......

#include <cstdio>
#include <set>
#include <vector>
using namespace std;

typedef struct studentnode {
    int number;
    int moral;
    int intelligence;
	bool operator<(const studentnode& rhs) const
	{
		if((moral + intelligence) != (rhs.moral + rhs.intelligence)) return (intelligence + moral) > (rhs.intelligence + rhs.moral);
		else if(moral != rhs.moral) return moral > rhs.moral;
		else return number < rhs.number;
	}
} Student;

int main()
{
	int n,l,h,countn = 0;
	scanf("%d %d %d",&n,&l,&h);
	vector<set<Student> > p(4);
    for(int i = 0;i < n;i++)
    {
    	Student temp;
        scanf("%d %d %d",&temp.number,&temp.moral,&temp.intelligence);
        if(temp.moral >= l && temp.intelligence >= l)
        {
            countn++;
            if(temp.moral >= h && temp.intelligence >= h) p[0].insert(temp);
            else if(temp.moral >= h) p[1].insert(temp);
            else if(temp.moral >= temp.intelligence) p[2].insert(temp);
            else p[3].insert(temp);
        }
    }
    printf("%d\n",countn);
    for(auto& q : p)
		for(auto& s : q) printf("%d %d %d\n",s.number,s.moral,s.intelligence);
}
