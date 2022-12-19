#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int mystrcmp(const char* str1, const char* str2);
int StringToNumber(char* str); 
char* NumberToString(int number); 
char* Uppercase(char* str1); 
char* Lowercase(char* str1); 
char* mystrrev(char* str);

int main()
{

    char* str1 = new char[32] {'U', 'k', 'r', 'a', 'i', 'n', 'e', ' ', 'i', 's', ' ', 'a', 'n', ' ', 'i', 'n', 'd', 'e', 'p', 'e', 'n', 'd', 'e', 'n', 't', ' ', 's', 't', 'a', 't', 'e', '\0'};
    char* str2 = new char[32] {'U', 'k', 'r', 'a', 'i', 'n', 'e', ' ', 'i', 's', ' ', 'a', 'n', ' ', 'i', 'n', 'd', 'e', 'p', 'e', 'n', 'd', 'e', 'n', 't', ' ', 's', 't', 'a', 't', 'e', '\0'};
	char* str = new char[6] {'1', '2', '3', '4', '5','\0'};
	int num = 0;
	int number = 56789;
	do
	{
		cout << "\n\nmystrcmp = 1\nStringToNumber = 2\n"
			"NumberToString = 3\nUppercase = 4\nLowercase = 5\nmystrrev = 6\nselect function: ";
		cin >> num;
		switch (num)
		{
		case 1: cout << "str1: " << str1 << endl << "str2: " << str2 << endl << "result: ";
			if (mystrcmp(str1, str2) == NULL)
				cout << ("str1 == str2\n");
			else if (mystrcmp(str1, str2) == 1)
				cout << ("str1 > str2\n");
			else
				cout << ("str1 < str2\n");
			break;
		case 2: cout << "str : " << str << endl << "result: " << StringToNumber(str) << endl;
			break;
		case 3: cout << "number:  " << number << endl << "result: " << NumberToString(number) << endl;
			break;
		case 4: cout << "str: " << str1 << endl << "result: " << Uppercase(str1) << endl;
			break;
		case 5: cout << "str: " << str1 << endl << "result: " << Lowercase(str1) << endl;
			break;
		case 6: cout << "str: " << str << endl << "result: " << mystrrev(str) << endl;
			break;
		default: num = 0;
			break;
		}
	} while (num != 0);



    delete[] str1;
    delete[] str2;
	delete[] str;
    return 0;
}

int mystrcmp(const char* str1, const char* str2)
{
    while (*str1)
    {
        if (*str1 != *str2) 
        {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int StringToNumber(char* str)
{
	int i, num;
	num = 0;
	for (i = 0; str[i] >= '0' && str[i] <= '9'; ++i)
		num = 10 * num + (str[i] - '0');
	return num;
}

char* NumberToString(int number)
{
	char* ptr;
	if (!number)
	{
		ptr = new char[2];
		ptr[0] = '0';
		ptr[1] = '\0';
		return ptr;
	}

	size_t size = 1;
	int temp = number;
	while (temp /= 10) ++size;
	bool negative = number < 0;
	if (negative) ++size;

	ptr = new char[size + 1];
	ptr[size] = '\0';
	if (negative) ptr[0] = '-';

	while (number)
	{
		ptr[--size] = abs(number % 10) + '0';
		number /= 10;
	}
	return ptr;
}

char* Uppercase(char* str1)
{
	size_t len = strlen(str1);
	char* result = new char[len];

	for (size_t i = 0; i < strlen(str1); i++)
	{
		result[i] = toupper(str1[i]);
	}
	return result;
}

char* Lowercase(char* str1)
{
	size_t len = strlen(str1);
	char* result = new char[len];
	for (size_t i = 0; i < strlen(str1); i++)
	{
		result[i] = tolower(str1[i]);
	}
	return result;
}
char* mystrrev(char* str)
{
	int i, n;
	char temp;
	size_t len = strlen(str);
	n = len - 1;
	for (i = 0; i <= (len / 2); i++)
	{
		temp = str[i];
		str[i] = str[n];
		str[n] = temp;
		n--;
	}
	return str;
}