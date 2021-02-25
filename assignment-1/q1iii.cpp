#include <iostream>
using namespace std;

int gcd(int n, int m)
{
    if (n < m)
    {
        for (int j = n; j > 2; j--)
        {
            if (n % j == 0 && m % j == 0)
            {
                return j;
            }
        }
        return -1;
    }
    else
    {
        for (int j = m; j > 2; j--)
        {
            if (n % j == 0 && m % j == 0)
            {
                return j;
            }
        }
        return -1;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "The greatest common divisor is: " << gcd(n, m) << endl;
}