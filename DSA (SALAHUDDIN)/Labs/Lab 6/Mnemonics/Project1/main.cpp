#include<iostream>
using namespace std;
char ** arr = new char*[8];
void makeAlphaArray(char ** & arr)
{
	for (int i = 0; i < 8; i = i + 1)
	{
		arr[i] = new char[3];
	}
	char ch = 65;
	for (int i = 0; i < 8; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			arr[i][j] = ch;
			ch = ch + 1;
			if (ch == 'Q' || ch == 'Z')
				ch = ch + 1;
		}
	}
}
void displayAlphaArray(char ** & arr)
{
	for (int i = 0; i < 8; i = i + 1)
	{
		for (int j = 0; j < 3; j = j + 1)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
int getStringLength(char * str)
{
	int length = 0 , i = 0;
	while (str[i] != '\0')
	{
		length = length + 1;
		i = i + 1;
	}
	return length;
}
void runMnemonics(char * str, char * output,int currPosi, int length)
{
	if (currPosi==length)
	{
		cout << output << " ";
		return;
	}
	else
	{
		for (int i = 0; i < 3; i = i + 1)
		{
			output[currPosi] = arr[str[currPosi]-50][i];
			runMnemonics(str , output , currPosi+1,length);
		}
	}
}
void listMnemonics(char * str)
{
	int length = getStringLength(str),currPosi=0;
	char * output = new char[length + 1];
	output[length] = '\0';
	runMnemonics(str,output,currPosi,length);
}

int main()
{
	makeAlphaArray(arr);
//	displayAlphaArray(arr);
	char str[9] = { "7234" };
	listMnemonics(str);
	cout << "\n\n\n";
	return 0;
}