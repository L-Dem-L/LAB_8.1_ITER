#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int Count(char* str)
{
    if (strlen(str) < 3)
        return 0;
    int k = 0;
    for (int i = 0; str[i + 2] != '\0'; i++)
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
            k++;
    }
    return k;
}

char* Change(char* str)
{
    size_t len = strlen(str);
    if (len < 3)
        return str;

    char* tmp = new char[len * 4 / 3 + 1];
    char* t = tmp;
    size_t i = 0;

    while (i < len && str[i + 2] != '\0')
    {
        if (str[i] == '*' && str[i + 1] == '*' && str[i + 2] == '*')
        {
            *t++ = '!';
            *t++ = '!';
            i += 3;
        }
        else
        {
            *t++ = str[i++];
        }
    }

    while (i < len)
    {
        *t++ = str[i++];
    }

    *t = '\0';

    return tmp;
}


int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of '***'" << endl;
    char* dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}
