//  Q1 part 6
// Animesh 101915210 2enc10
#include <iostream>
#include <string>
using namespace std;

void vowelsWords(string str)
{
    int vowels = 0;
    int words = 0;
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
        else if (str[i] == ' ' )
        {
            words++;
        }
    }
    cout << "Total number of words: " << words << endl;
    cout << "Total number of vowels: " << vowels << endl;
}


int main()
{
    string string_input;
    cout << "Enter a string: \n";
    getline(cin, string_input);
    vowelsWords(string_input);
}
