//基本同B级1002。

#include <iostream>
using namespace std;

int ctoi(char c) {return (int)(c - '0');}

string itos(int i)
{
  switch(i)
  {
    case 0:return "zero";break;
    case 1:return "one";break;
    case 2:return "two";break;
    case 3:return "three";break;
    case 4:return "four";break;
    case 5:return "five";break;
    case 6:return "six";break;
    case 7:return "seven";break;
    case 8:return "eight";break;
    case 9:return "nine";break;
  }
}

int main()
{
  int sum = 0;
  char temp;
  for(;(temp = cin.get()) && (temp != '\n');)
    sum += ctoi(temp);
  string answer = "";bool flag = true;
    if(sum)
    {
        for(;sum > 0;)
    {
        if(flag)
        {
            answer = itos(sum % 10);
            sum /= 10;
            flag = false;
        }
        else
        {
            answer = itos(sum % 10) + " " + answer;
            sum /= 10;
        }
      }
    }
  else answer = "zero";
  cout<<answer<<endl;
}
