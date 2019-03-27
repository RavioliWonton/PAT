//"并不是所有狼人都在撒谎"的意思就是两个撒谎的一个狼人一个好人，别想太多。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	vector<int> input(n);
	for(int i = 0;i < n;i++) cin>>input[i];
	if(count_if(input.begin(),input.end(),[&](int i)->bool{return i < 0;}) == 2)
    {
         vector<int> lie(2);
         copy_if(input.begin(),input.end(),lie.begin(),[&](int i)->bool{return i < 0;});
         pair<int, int> wolf;

    }
    else cout<<"No Solution"<<endl;
}
