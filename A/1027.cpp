#include <iostream>
#include <string>
using namespace std;
int main()
{
    int red,green,blue;
    cin>>red>>green>>blue;
    auto f = [=](int colour) -> string
                        {
                            string result = "";
                            switch(colour/13)
                            {
                                case 0:result.append("0");break;
                                case 10:result.append("A");break;
                                case 11:result.append("B");break;
                                case 12:result.append("C");break;
                                default:result.append(to_string(colour/13));break;
                            }
                            switch(colour%13)
                            {
                                case 10:result.append("A");break;
                                case 11:result.append("B");break;
                                case 12:result.append("C");break;
                                default:result.append(to_string(colour%13));break;
                            }
                            return result;
                        };
    cout<<"#"<<f(red)<<f(green)<<f(blue)<<endl;
}
