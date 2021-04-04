#include <iostream>
using namespace std;

// * q5
void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        cout << "Move disk from " << a << " to " << c << " using " << b << endl;
        TOH(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    cin >> n;
    TOH(n, 1, 2, 3);

    return 0;
}