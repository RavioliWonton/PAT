//国际惯例，稀疏表........

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	int number;
	int cprog;
	int math;
	int english;
	int average;
} student;

typedef struct {
	int number;
	char subject;
} ranks;

typedef struct {
	ranks ranks[4];
} studentrank;

bool cmpc(student a,student b) {return a.cprog > b.cprog;}
bool cmpm(student a,student b) {return a.math > b.math;}
bool cmpe(student a,student b) {return a.english > b.english;}
bool cmpa(student a,student b) {return a.average > b.average;}
bool cmpr(ranks a,ranks b) {return a.number < b.number;}

int main()
{
	int n,m;
	cin>>n>>m;
	student (*p) = new student[n];
	for(int i = 0;i < n;i++)
	{
		cin>>p[i].number>>p[i].cprog>>p[i].math>>p[i].english;
		p[i].average = (p[i].cprog + p[i].math + p[i].english) / 3;
	}
	studentrank r[100000];
	sort(p,p+n,cmpc);for(int i = 0;i < n;i++) {r[p[i].number].ranks[0].number = i+1;r[p[i].number].ranks[0].subject = 'C';}
	sort(p,p+n,cmpm);for(int i = 0;i < n;i++) {r[p[i].number].ranks[1].number = i+1;r[p[i].number].ranks[1].subject = 'M';}
	sort(p,p+n,cmpe);for(int i = 0;i < n;i++) {r[p[i].number].ranks[2].number = i+1;r[p[i].number].ranks[2].subject = 'E';}
	sort(p,p+n,cmpa);for(int i = 0;i < n;i++) {r[p[i].number].ranks[3].number = i+1;r[p[i].number].ranks[3].subject = 'A';}
	delete [] p;
	cout<<r[2].ranks[1].number<<endl;
	/*for(int i = 0;i < m;i++)
	{
		int request;
		cin>>request;
		if(r[request].ranks[0].number < 5) {}
			//cout<<(*min_element(r[request].ranks,(r[request].ranks)+4,cmpr)).number<<" "<<(*min_element(r[request].ranks,(r[request].ranks)+4,cmpr)).subject<<"\n";
		else cout<<"N/A\n";
	}*/
}
