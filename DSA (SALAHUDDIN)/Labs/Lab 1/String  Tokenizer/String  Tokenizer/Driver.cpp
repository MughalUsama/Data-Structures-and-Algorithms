#include<iostream>
using namespace std;
int calcStringLength(const char * str)
{
	int index = 0 , length = 0;
	while (str[index] != '\0')
	{
		length = length + 1;
		index = index + 1;
	}
	return length;
}
char * stringTokenizer(char * str, const char * delim)
{
	bool tokenFound = false , delimFound;
	int index = 0 , stringLength = calcStringLength(str);
	char * token = new char[stringLength];
	token[0] = '\0';
	while (str[index] != '\0' && tokenFound == false)
	{
		int delimIndex = 0;
		delimFound = false;
		while (delim[delimIndex] != '\0' && delimFound == false)
		{
			if (str[index] == delim[delimIndex])
			{
				int delimIndex2 = 0 ;
				bool delimFound2 = false;
				while (delim[delimIndex2] != '\0' && delimFound2 == false)
				{
					if (str[index + 1] == delim[delimIndex2])
						delimFound2 = true;
					delimIndex2 = delimIndex2 + 1;
				}
				if (delimFound2 == false)
					delimFound = true;
			}
			delimIndex = delimIndex + 1;
		}
		if(delimFound == true)
		{
			index = index + 1;
			int tokenIndex = 0;
			bool finalCheck;
			while (str[index] != '\0' && tokenFound == false)
			{
				int delimIndex3 = 0;
				bool delimFound3 = false;
				while (delim[delimIndex3] != '\0' && delimFound3 == false)
				{
					if (str[index] == delim[delimIndex3])
						delimFound3 = true;
					delimIndex3 = delimIndex3 + 1;
				}
				if (delimFound3 == true)
				{
					tokenFound = true;
					int finalIndex;
					for (int j = index+1 , i = 0 ; j <= stringLength; i = i + 1 , j = j + 1)
					{
						str[i] = str[j];
						finalIndex = i;
					}
					str[finalIndex] = '\0';
				}
				else {
					token[tokenIndex] = str[index];
					tokenIndex = tokenIndex + 1;
				}
				index = index + 1;
				finalCheck = delimFound3;
			}
			token[tokenIndex] = '\0';
			if (finalCheck == false)
				token[0] = '\0';
		}
		index = index + 1;
	}
	return token;
}
int main()
{
	char string[30] = "- This, a sample string.";
	char delim[5] = " ,.-";
	cout << stringTokenizer(string, delim) << "\n";
	cout << stringTokenizer(string, delim) << "\n";
	cout << stringTokenizer(string, delim) << "\n";
	cout << stringTokenizer(string, delim) << "\n";
	cout << stringTokenizer(string, delim) << "\n";
	cout << stringTokenizer(string, delim) << "\n";
	cout << "\n\n\n";
	return 0;
}