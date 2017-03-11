#include <iostream>
using namespace std;

int ctoi(char c) {return (int)(c - '0');}

string itos(int i)
{
	switch(i)
	{
		case 0:return "ling";break;
		case 1:return "yi";break;
		case 2:return "er";break;
		case 3:return "san";break;
		case 4:return "si";break;
		case 5:return "wu";break;
		case 6:return "liu";break;
		case 7:return "qi";break;
		case 8:return "ba";break;
		case 9:return "jiu";break;
	}
}

int main()
{
	int sum = 0;
	char temp;
	for(;(temp = cin.get()) && (temp != '\n');)
		sum += ctoi(temp);
	string answer = "";bool flag = true;
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
	cout<<answer<<endl;
}
