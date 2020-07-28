#include <iostream>

using namespace std;


char *stringTokenizer(char *str, const char *delim);
int findDelimeter(char *str, const char * delim);
void copyToken(char * token, char *str, int delimIndex);
void resizeString(char *str, int delimIndex);




int main()
{
	char str[30] = "This, a sample string";
	char * token = stringTokenizer(str, ".");
	cout << "String after token: \n\t\"" << str << "\"\n\n";
	cout << "Token :\n\t\"" << token << "\"";

	token = stringTokenizer(str, ".");
	cout << "\n\nString after token: \n\t\"" << str << "\"\n\n";
	cout << "Token :\n\t\"" << token << "\"";

	token = stringTokenizer(str, ".");
	cout << "\n\nString after token: \n\t\"" << str << "\"\n\n";
	cout << "Token :\n\t\"" << token << "\"";

	token = stringTokenizer(str, ".");
	cout << "\n\nString after token: \n\t\"" << str << "\"\n\n";
	cout << "Token :\n\t\"" << token << "\"";

	token = stringTokenizer(str, ".");
	cout << "\n\nString after token: \n\t\"" << str << "\"\n\n";
	cout << "Token :\n\t\"" << token << "\"";

	system("pause");
	return 0;
}

char *stringTokenizer(char *str, const char *delim)
{
	int delimIndex = findDelimeter(str, delim);
	if (delimIndex != -1)
	{
		char *token = new char[delimIndex + 1];
		copyToken(token, str, delimIndex);
		resizeString(str, delimIndex);
		return token;
	}
	else
	{
		char *token = new char[1];
		copyToken(token, str, delimIndex);
		resizeString(str, delimIndex);
		return token;
	}
}


int findDelimeter(char *str, const char * delim)
{
	int i = 0;
	for (int i = 0; str[i] != '\0'; i = i + 1)
	{
		int j = 0;
		while (delim[j] != '\0')
		{
			if (str[i] == delim[j])
			{
				return i;
			}
			j = j + 1;
		}

	}
	return -1;
}

void copyToken(char * token, char *str, int delimIndex)
{
	for (int i = 0; i < delimIndex; i = i + 1)
	{
		token[i] = str[i];
	}
	if (delimIndex == -1)
	{
		token[0] = '\0';
	}
	else
	{
		token[delimIndex] = '\0';
	}
}

void resizeString(char *str, int delimIndex)
{
	for (int i = 0; str[i + delimIndex] != '\0'; i = i + 1)
	{
		str[i] = str[i + delimIndex + 1];
	}
}
