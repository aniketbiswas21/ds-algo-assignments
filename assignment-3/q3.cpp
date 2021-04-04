#include <iostream>
using namespace std;

// *Q3
int ncr(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }
    return ncr(n - 1, r - 1) + ncr(n - 1, r);
}

int main()
{
    cout << "Enter number n and r: " << endl;
    int n, r;
    cin >> n >> r;
    int ans;
    ans = ncr(n, r);
    cout << ans << endl;
}