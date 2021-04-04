#include <iostream>
#include <string>
using namespace std;

// * Q1(i)
int lengthFun(string str)
{
    int l = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}

// * Q1(ii)
void toLowerCase(string &str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
    }
}

// * Q1(iii)
void vowelsWords(string str)
{
    int vowels = 0;
    int words = 1; // if you are keeping this 0 then for 2 words it is printing 1 i.e it is counting whitespace between words and returning that. 
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
        {
            vowels++;
        }
        else if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
        {
            vowels++;
        }
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i - 1] != ' ' && str[i] == ' ')
        {
            words++;
        }
    }
    cout << "Total number of words: " << words + 1 << endl;
    cout << "Total number of vowels: " << vowels << endl;
}

// * Q1(iv)
void isValid(string str)
{
    for (int i = 0; str[i] != '\0';)
    {
        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
        {
            i++;
        }
        else
        {
            cout << "Invalid string" << endl;
            return;
        }
    }
    cout << "Valid string" << endl;
}

// * Q1(v)
void reverseString(string &str)
{
    int l = lengthFun(str);
    char s[l];
    int j = l - 1;
    for (int i = 0; i < l; i++)
    {
        s[i] = str[j--];
    }
    s[l] = '\0';
    str = s;
}

// * Q1(vi)
void palindrome(string str)
{
    int i = 0;
    int l = lengthFun(str);
    int j = l - 1;
    cout << j << endl;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            cout << "Not a paindrome" << endl;
            return;
        }
        i++;
        j--;
    }
    cout << "The given string is a palindrome" << endl;
}

// *Q1(vii)
void stringDuplicates(string s)
{
    toLowerCase(s);
    long int h = 0;
    long int l = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        l = 1;
        int index = s[i] - 97;
        l = l << index;
        if ((l & h) > 0)
        {
            cout << s[i] << " repeats " << endl;
        }
        else
        {
            h = l | h;
        }
    }
}

int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    // cin >> s;
    cout << "The length of the string is: " << lengthFun(s) << endl;
    toLowerCase(s);
    cout << s << endl;
    isValid(s);
    reverseString(s);
    cout << s << endl;
    palindrome(s);
    stringDuplicates(s);
    vowelsWords(s);
}
