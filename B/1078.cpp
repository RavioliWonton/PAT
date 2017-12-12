#include <iostream>
using namespace std;
int main()
{
    char flag;
    cin>>flag;
    cin.sync();
    string input;
    getline(cin,input);
    if(flag == 'C')
    {
        auto start = input.begin();
        for(auto it = input.begin() + 1;it != input.end();it++)
        {
            cout<<input<<endl;
            cout<<"input[start = "<<start - input.begin()<<"] = "<<*start<<"\ninput[it = "<<it - input.begin()<<"] = "<<*it<<endl;
            if(*start != *it)
            {
                int length = it - start;
                if(length > 1) input.replace(start,it,{to_string(length) + *start});
                it -= length - (to_string(length).size() + 1);
                start = it;
            }
        }
        cout<<input<<endl;
    }
    else if(flag == 'D')
    {

    }
}
