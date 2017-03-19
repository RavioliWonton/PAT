#include <iostream>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;

bool isPrime(int n)
{
	if(n == 1) return false;
    else if(n == 2) return true;
    else
    {
        for(int i = 2; i <= sqrt(n); i++)
            if(!(n % i)) return false;
        return true;
    }
}

int main()
{
    int number;
    for(; cin>>number && number > 0;)
    {
        int radix;
        cin>>radix;
        if(isPrime(number))
        {
            deque<int> p;
            for(; number > 0;)
            {
                p.push_front(number % radix);
                number /= radix;
            }
            reverse(p.begin(),p.end());
            int result = 0;
            for(int i = 0; !p.empty(); i++)
            {
                result += p.back()*pow(radix,i);
                p.pop_back();
            }
            if(isPrime(result)) cout<<"Yes\n";
            else cout<<"No\n";
        }
        else cout<<"No\n";
    }
}
