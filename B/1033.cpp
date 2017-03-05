//题目只说第二个字符串非空，没说第一个，神坑，请注意。

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string a,b;
    getline(cin,a);
    string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_,.-";
    bool (*p) = new bool[c.length()];memset(p,true,sizeof(bool)*c.length());
    for(int i = 0;i < a.length();i++)
    {
        switch(a[i])
        {
            case 'A':p[0] = p[26] = false;break;
            case 'B':p[1] = p[27] = false;break;
            case 'C':p[2] = p[28] = false;break;
            case 'D':p[3] = p[29] = false;break;
            case 'E':p[4] = p[30] = false;break;
            case 'F':p[5] = p[31] = false;break;
            case 'G':p[6] = p[32] = false;break;
            case 'H':p[7] = p[33] = false;break;
            case 'I':p[8] = p[34] = false;break;
            case 'J':p[9] = p[35] = false;break;
            case 'K':p[10] = p[36] = false;break;
            case 'L':p[11] = p[37] = false;break;
            case 'M':p[12] = p[38] = false;break;
            case 'N':p[13] = p[39] = false;break;
            case 'O':p[14] = p[40] = false;break;
            case 'P':p[15] = p[41] = false;break;
            case 'Q':p[16] = p[42] = false;break;
            case 'R':p[17] = p[43] = false;break;
            case 'S':p[18] = p[44] = false;break;
            case 'T':p[19] = p[45] = false;break;
            case 'U':p[20] = p[46] = false;break;
            case 'V':p[21] = p[47] = false;break;
            case 'W':p[22] = p[48] = false;break;
            case 'X':p[23] = p[49] = false;break;
            case 'Y':p[24] = p[50] = false;break;
            case 'Z':p[25] = p[51] = false;break;
            case '0':p[52] = false;break;
            case '1':p[53] = false;break;
            case '2':p[54] = false;break;
            case '3':p[55] = false;break;
            case '4':p[56] = false;break;
            case '5':p[57] = false;break;
            case '6':p[58] = false;break;
            case '7':p[59] = false;break;
            case '8':p[60] = false;break;
            case '9':p[61] = false;break;
            case '_':p[62] = false;break;
            case ',':p[63] = false;break;
            case '.':p[64] = false;break;
            case '-':p[65] = false;break;
            case '+':p[0] = p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = p[8] = p[9] = p[10] = p[11] = p[12] = p[13] = p[14] = p[15] = p[16] = p[17] = p[18] = p[19] = p[20] = p[21] = p[22] = p[23] = p[24] = p[25] = false;break;
        }
    }
    cin>>b;
    for(int i = 0;i < b.length();i++)
        if(c.find(b[i]) < c.length() && p[c.find(b[i])]) cout.put(b[i]);
    cout<<endl;
    delete [] p;
}
