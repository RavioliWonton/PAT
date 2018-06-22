//题目只说第二个字符串非空，没说第一个，神坑，请注意。
//还有本题其实稀疏表最好，但是我就不的！

#include <iostream>
#include <vector>
using namespace std;
int main()
{
	char ch;
    string c = "abcdefghijklmnopqrstuvwxyz0123456789_,.-+";
    vector<bool> p(c.size(),true);
    for(;(ch = cin.get()) != '\n';)
    {
    	if(isupper(ch)) p[ch - 'A'] = false;
    	else if(isdigit(ch)) p[26 + ch - '0'] = false;
    	else if(ch == '_') p[36] = false;
    	else if(ch == ',') p[37] = false;
    	else if(ch == '.') p[38] = false;
    	else if(ch == '-') p[39] = false;
    	else if(ch == '+') p[40] = false;
    }
    for(;(ch = cin.get()) != '\n';)
    	if((c.find(ch) == string::npos ? false : p[c.find(ch)]) || (p[40] && p[c.find(tolower(ch))])) cout.put(ch);
    cout<<endl;
}
