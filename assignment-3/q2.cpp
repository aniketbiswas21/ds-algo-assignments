#include <iostream>
using namespace std;

// * Q2
int factorial(int num)
{
    if (num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}

int main()
{
    cout << "Enter a number: " << endl;
    int n;
    cin >> n;
    int ans;
    ans = factorial(n);
    cout << ans << endl;
}