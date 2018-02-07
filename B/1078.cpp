#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    string flag;
    getline(cin,flag);
    string input;
    getline(cin,input);
    if(flag == "C")
    {
        auto start = input.begin();
        for(auto it = input.begin() + 1;it != input.end();it++)
        {
            //cout<<input<<endl;
            //cout<<"input[start = "<<start - input.begin()<<"] = "<<*start<<"\ninput[it = "<<it - input.begin()<<"] = "<<*it<<endl;
            if(*start != *it)
            {
                int length = it - start;
                if(length > 1) input.replace(start,it,{to_string(length) + *start});
                it -= length - (to_string(length).size() + 1) + 1;
                start = it;
            }
            else cout<<*it;
        }
        if(*start == input.back())
        {
            int length = input.end() - start;
            if(length > 1) input.replace(start,input.end(),{to_string(length) + *start});
        }
    }
    else if(flag == "D")
    {
        auto itb = input.end();
        for(auto it = input.begin();it != input.end();it++)
        {
            if(isdigit(*it) && itb == input.end()) itb = it;
            else if(!isdigit(*it) && itb != input.end())
            {
                stringstream ss(string(itb,it));
                size_t length;
                ss >> length;
                input.replace(itb,it,length - 1,*it);
                itb = input.end();
            }
        }
    }
}
