#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

typedef struct {
    char name[5];
    vector<int> course;
} student;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	vector<student> v;
	for(int i = 0;i < k;i++)
    {
        int c,sn;
        scanf("%d %d",&c,&sn);
        for(int j = 0;j < sn;j++)
        {
            char temp[5];
            scanf("%s",&temp);
            auto f = find_if(v.begin(),v.end(),[&temp](student &a)->bool{return (strncmp(a.name,temp,4) < 0 ? false : !strncmp(a.name,temp,4));});
            if(f != v.end()) (*f).course.push_back(c);
            else
            {
                student temps;
                strncpy(temps.name,temp,4);
                temps.course.push_back(c);
                v.push_back(temps);
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        char temp[5];
        scanf("%s",&temp);
        printf("%s ",temp);
        auto f = find_if(v.begin(),v.end(),[&temp](student &a)->bool{return (strncmp(a.name,temp,4) < 0 ? false : !strncmp(a.name,temp,4));});
        if(f != v.end())
        {
            printf("%d",(*f).course.size());
            if((*f).course.size())
            {
                sort((*f).course.begin(),(*f).course.end());
                for_each((*f).course.begin(),(*f).course.end(),[&](int i)->void{printf(" %d",i);});
            }
            printf("\n");
        }
        else printf("0\n");
    }
}
