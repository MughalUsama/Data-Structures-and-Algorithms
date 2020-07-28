#include <iostream>
#include "myStack.h"
#include "myStack.cpp"
using namespace std;


Stack <char> s;

void mnemonics(const char * str)
{
	if (*str=='\0')
	{
		s.display();
		cout << "  ";
		return;
	}
	 if (*str == '2')
	{
		s.push('A');
		mnemonics(str + 1);
		s.pop();
		
		s.push('B');
		mnemonics(str + 1);
		s.pop();

		s.push('C');
		mnemonics(str + 1);
		s.pop();
	}
	else if (*str == '3')
	{
		s.push('D');
		mnemonics(str + 1);
		s.pop();

		s.push('E');
		mnemonics(str + 1);
		s.pop();

		s.push('F');
		mnemonics(str + 1);
		s.pop();

	}
	else if (*str == '4')
	{
		s.push('G');
		mnemonics(str + 1);
		s.pop();

		s.push('H');
		mnemonics(str + 1);
		s.pop();

		s.push('I');
		mnemonics(str + 1);
		s.pop();
	}
	else if (*str == '5')
	{
		s.push('J');
		mnemonics(str + 1);
		s.pop();

		s.push('K');
		mnemonics(str + 1);
		s.pop();

		s.push('L');
		mnemonics(str + 1);
		s.pop();
	}
	else if (*str == '6')
	{
		s.push('M');
		mnemonics(str + 1);
		s.pop();

		s.push('N');
		mnemonics(str + 1);
		s.pop();

		s.push('O');
		mnemonics(str + 1);
		s.pop();

	}
	else if (*str == '7')
	{
		s.push('P');
		mnemonics(str + 1);
		s.pop();

		s.push('R');
		mnemonics(str + 1);
		s.pop();

		s.push('S');
		mnemonics(str + 1);
		s.pop();

	}
	else if (*str == '8')
	{
		s.push('T');
		mnemonics(str + 1);
		s.pop();

		s.push('U');
		mnemonics(str + 1);
		s.pop();

		s.push('V');
		mnemonics(str + 1);
		s.pop();

	}
	else if (*str == '9')
	{
		s.push('W');
		mnemonics(str + 1);
		s.pop();

		s.push('X');
		mnemonics(str + 1);
		s.pop();

		s.push('Y');
		mnemonics(str + 1);
		s.pop();
	}
	else
	{
		mnemonics(str + 1);
	}
	
	
}
int main()
{
	/*char str[30];
	cin >> str;
	cout << '\n';
	mnemonics(str);
	*/
	//cout << char();
	//cout << char(('7' - '0' +'A'+3*('7' - '0'-3)));
	int key = null;

	cout << "\n";
	return 0;
}