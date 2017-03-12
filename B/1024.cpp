//指数可能很大，double搞不掂，只能上deque.......


#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    char sign;
    cin>>sign;
    if(sign == '-') cout<<"-";
    deque<char> base;char buffer;
    for(; (buffer = cin.get()) && (buffer != 'E');) base.push_back(buffer);
    int index;
    cin>>sign>>index;
    if(index)
    {
        if(sign == '+')
        {
            if(index > base.end() - find(base.begin(),base.end(),'.') - 1)
            {
                base.erase(base.begin()+1);
                int difference = index - base.size() + 1;
                for(int i = 0; i < difference; i++) base.push_back('0');
            }
            else
            {
                base.erase(base.begin()+1);
                int difference = base.size() - 1- index;
                for(int i = 0; i < difference; i++)
                {
                    buffer = *(base.end()-1);
                    base.pop_back();
                    base.push_front(buffer);
                }
                if(difference) base.push_back('.');
                for(int i = 0; i < difference; i++)
                {
                    buffer = *base.begin();
                    base.pop_front();
                    base.push_back(buffer);
                }
            }
        }
        else if(sign == '-')
        {
            base.erase(base.begin()+1);
            for(int i = 0; i < index - 1; i++) base.push_front('0');
            base.push_front('.');
            base.push_front('0');
        }
    }
    for(deque<char>::iterator i = base.begin(); i != base.end(); i++) cout<<*i;
    cout<<endl;
}
