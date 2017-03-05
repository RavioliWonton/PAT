#include <iostream>
#include <string>
#include <limits>
using namespace std;

int StoOnes(string s)
{
    if(s[0] == 't' && s[1] == 'r' && s[2] == 'e') return 0;
    else if(s[0] == 'j' && s[1] == 'a' && s[2] == 'n') return 1;
    else if(s[0] == 'f' && s[1] == 'e' && s[2] == 'b') return 2;
    else if(s[0] == 'm' && s[1] == 'a' && s[2] == 'r') return 3;
    else if(s[0] == 'a' && s[1] == 'p' && s[2] == 'r') return 4;
    else if(s[0] == 'm' && s[1] == 'a' && s[2] == 'y') return 5;
    else if(s[0] == 'j' && s[1] == 'u' && s[2] == 'n') return 6;
    else if(s[0] == 'j' && s[1] == 'l' && s[2] == 'y') return 7;
    else if(s[0] == 'a' && s[1] == 'u' && s[2] == 'g') return 8;
    else if(s[0] == 's' && s[1] == 'e' && s[2] == 'p') return 9;
    else if(s[0] == 'o' && s[1] == 'c' && s[2] == 't') return 10;
    else if(s[0] == 'n' && s[1] == 'o' && s[2] == 'v') return 11;
    else if(s[0] == 'd' && s[1] == 'e' && s[2] == 'c') return 12;
    else if(s[0] == 't' && s[1] == 'a' && s[2] == 'm') return 13;
    else if(s[0] == 'h' && s[1] == 'e' && s[2] == 'l') return 26;
    else if(s[0] == 'm' && s[1] == 'a' && s[2] == 'a') return 39;
    else if(s[0] == 'h' && s[1] == 'u' && s[2] == 'h') return 52;
    else if(s[0] == 't' && s[1] == 'o' && s[2] == 'u') return 65;
    else if(s[0] == 'k' && s[1] == 'e' && s[2] == 's') return 78;
    else if(s[0] == 'h' && s[1] == 'e' && s[2] == 'i') return 91;
    else if(s[0] == 'e' && s[1] == 'l' && s[2] == 'o') return 104;
    else if(s[0] == 's' && s[1] == 'y' && s[2] == 'y') return 117;
    else if(s[0] == 'l' && s[1] == 'o' && s[2] == 'k') return 130;
    else if(s[0] == 'm' && s[1] == 'e' && s[2] == 'r') return 143;
    else if(s[0] == 'j' && s[1] == 'o' && s[2] == 'u') return 156;
}

int StoTens(string s)
{
    if(s[0] == 't' && s[1] == 'a' && s[2] == 'm') return 1;
    else if(s[0] == 'h' && s[1] == 'e' && s[2] == 'l') return 2;
    else if(s[0] == 'm' && s[1] == 'a' && s[2] == 'a') return 3;
    else if(s[0] == 'h' && s[1] == 'u' && s[2] == 'h') return 4;
    else if(s[0] == 't' && s[1] == 'o' && s[2] == 'u') return 5;
    else if(s[0] == 'k' && s[1] == 'e' && s[2] == 's') return 6;
    else if(s[0] == 'h' && s[1] == 'e' && s[2] == 'i') return 7;
    else if(s[0] == 'e' && s[1] == 'l' && s[2] == 'o') return 8;
    else if(s[0] == 's' && s[1] == 'y' && s[2] == 'y') return 9;
    else if(s[0] == 'l' && s[1] == 'o' && s[2] == 'k') return 10;
    else if(s[0] == 'm' && s[1] == 'e' && s[2] == 'r') return 11;
    else if(s[0] == 'j' && s[1] == 'o' && s[2] == 'u') return 12;
}

string OnestoS(int i)
{
    switch(i)
    {
        case 12:return "dec";
        case 11:return "nov";
        case 10:return "oct";
        case 9:return "sep";
        case 8:return "aug";
        case 7:return "jly";
        case 6:return "jun";
        case 5:return "may";
        case 4:return "apr";
        case 3:return "mar";
        case 2:return "feb";
        case 1:return "jan";
        case 0:return "tret";
    }
}

int main()
{
    int n;
    cin>>n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string s;
    for(int j = 0;j < n;j++)
	{
        getline(cin,s);
        if(s[0] >= 48 && s[0] <=57)
        {
            switch(stoi(s) / 13)
            {
                case 12:if(stoi(s) == 156) {cout<<"jou"<<endl;}else {cout<<"jou " + OnestoS(stoi(s) - 12*13)<<endl;}break;
                case 11:if(stoi(s) == 143) {cout<<"mer"<<endl;}else {cout<<"mer " + OnestoS(stoi(s) - 11*13)<<endl;}break;
                case 10:if(stoi(s) == 130) {cout<<"lok"<<endl;}else {cout<<"lok " + OnestoS(stoi(s) - 10*13)<<endl;}break;
                case 9:if(stoi(s) == 117) {cout<<"syy"<<endl;}else {cout<<"syy " + OnestoS(stoi(s) - 9*13)<<endl;}break;
                case 8:if(stoi(s) == 104) {cout<<"elo"<<endl;}else {cout<<"elo " + OnestoS(stoi(s) - 8*13)<<endl;}break;
                case 7:if(stoi(s) == 91) {cout<<"hei"<<endl;}else {cout<<"hei " + OnestoS(stoi(s) - 7*13)<<endl;}break;
                case 6:if(stoi(s) == 78) {cout<<"kes"<<endl;}else {cout<<"kes " + OnestoS(stoi(s) - 6*13)<<endl;}break;
                case 5:if(stoi(s) == 65) {cout<<"tou"<<endl;}else {cout<<"tou " + OnestoS(stoi(s) - 5*13)<<endl;}break;
                case 4:if(stoi(s) == 52) {cout<<"huh"<<endl;}else {cout<<"huh " + OnestoS(stoi(s) - 4*13)<<endl;}break;
                case 3:if(stoi(s) == 39) {cout<<"maa"<<endl;}else {cout<<"maa " + OnestoS(stoi(s) - 3*13)<<endl;}break;
                case 2:if(stoi(s) == 26) {cout<<"hel"<<endl;}else {cout<<"hel " + OnestoS(stoi(s) - 2*13)<<endl;}break;
                case 1:if(stoi(s) == 13) {cout<<"tam"<<endl;}else {cout<<"tam " + OnestoS(stoi(s) - 13)<<endl;}break;
                case 0:cout<<OnestoS(stoi(s))<<endl;break;
            }
        }
        else
        {
            if(s.length() <= 4) cout<<StoOnes(s)<<endl;
            else cout<<StoTens(s.substr(0,3)) * 13 + StoOnes(s.substr(4,s.length()-1))<<endl;
        }
	}
}
