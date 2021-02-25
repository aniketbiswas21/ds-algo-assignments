#include <iostream>
using namespace std;

bool isPrime(int n)
{
    for (int j = 2; j < n; j++)
    {
        if (n % j == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    cout << isPrime(n);
}