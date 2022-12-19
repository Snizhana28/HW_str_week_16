#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

string change_word_in_text(const char* text, const char* old_word, const char* new_word);
void change_letter_in_text(const char* text);
void letters_in_text(const char* text);
void numbers_in_text(const char* text);

int main()
{
	string text, old_word, new_word;
	cout << "Input: ";
	getline(cin, text);
	cout << "Old word: ";
	getline(cin, old_word);
	cout << "New word: ";
	getline(cin, new_word);
	string res = change_word_in_text(text.c_str(), old_word.c_str(), new_word.c_str());
	cout << "Result = " << res << endl;
    change_letter_in_text(text.c_str());
    letters_in_text(text.c_str());
    numbers_in_text(text.c_str());
    
	return 0;

}
string change_word_in_text(const char* text, const char* old_word, const char* new_word)
{
    string result;
    uint32_t index;
    bool trigger = true;
    for (size_t i = 0, j = 0; i < strlen(text); i++)
    {
        trigger = true;
        if (text[i] == old_word[j])
        {
            index = i;
            for (; j < strlen(old_word); j++)
            {
                if (text[index] != old_word[j])
                {
                    trigger = false;
                    break;
                }
                index++;
            }
            if (trigger != false)
            {
                result += new_word;
                i = index - 1;
            }
            else {
                j = 0;
                result += text[i];
            }
        }
        else {
            result += text[i];
        }
    }
    return result;
}
void change_letter_in_text(const char* text)
{
    cout << (char)toupper(text[0]);
    for (int i = 1; i < strlen(text); i++)
        cout << text[i];
}
void letters_in_text(const char* text)
{
    int i = 0;
    int j = 0;
    int alpha[26] = {0};
    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            j = text[i] - 'a';
            ++alpha[j];
        }
        ++i;
    }
    cout << endl;
    for (i = 0; i < 26; i++)
        cout << char(i + 'a') << " : " << alpha[i] << endl;
}
void numbers_in_text(const char* text)
{
    int sum = 0;
    for (unsigned int i = 0; i < strlen(text);i++)
    {
        if (isdigit(text[i]))
            sum++;
    }
    cout << "Numbers in string = " << sum << endl;
}
