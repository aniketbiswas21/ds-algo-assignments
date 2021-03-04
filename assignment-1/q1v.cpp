#include <iostream>
using namespace std;

void determine(int n)
{
    switch (n)
    {
    case 1:
        cout << "One";
        break;
    case 2:
        cout << "Two";
        break;
    case 3:
        cout << "Three";
        break;
    case 4:
        cout << "Four";
        break;
    case 5:
        cout << "Five";
        break;
    case 6:
        cout << "Six";
        break;
    case 7:
        cout << "Seven";
        break;
    case 8:
        cout << "Eight";
        break;
    case 9:
        cout << "Nine";
        break;
    default:
        cout << "Enter a valid number";
        break;
    }
}

int main()
{
    int n;
    cout << "Enter a number between 1 and 9" << endl;
    cin >> n;
    determine(n);
}