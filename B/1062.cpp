#include <functional>
#include <algorithm>
using namespace std;

int main()
{
	int n1,n2,m1,m2,k,countn = 0;
	scanf("%d/%d %d/%d %d",&n1,&m1,&n2,&m2,&k);
    function<int(int,int)> gcd = [&](int a,int b)->int{return b ? gcd(b, a % b) : a;};
    auto choosefrac = [&](pair<int, int> f1,pair<int, int> f2,int flag)->pair<int, int>{return (f1.first*f2.second < f2.first*f1.second ? (flag ? f1 : f2) : (flag ? f2 : f1));};
    for(int l = choosefrac(make_pair(n1,m1),make_pair(n2,m2),1).first * k / choosefrac(make_pair(n1,m1),make_pair(n2,m2),1).second + 1;choosefrac(make_pair(n1,m1),make_pair(n2,m2),0).first * k > choosefrac(make_pair(n1,m1),make_pair(n2,m2),0).second * l;l++)
        if(gcd(l,k) == 1) printf("%s%d/%d",(countn++ ? " " : ""),l,k);
	printf("\n");
}
