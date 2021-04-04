#include <iostream>
using namespace std;

// * Q6
int fibonacci(int i)
{
    if (i == 0)
    {
        return 0;
    }
    if (i == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(i - 2) + fibonacci(i - 1);
    }
}

int main()
{
    int number;
    cout << "Enter an index for which you wish to find the fibonacci number: ";
    cin >> number;
    int ans = fibonacci(number);
    cout << ans << endl;
}