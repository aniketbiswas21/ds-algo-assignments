#include <bits/stdc++.h>
using namespace std;

int max(int *a, int l)
{
    int m = INT_MIN;
    for (int i = 0; i < l; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}

int *removeDuplicates(int *a, int n)
{
    int *c = new int[n];
    int m = max(a, n);
    int *b = new int[m + 1];
    // * Hashing
    for (int i = 0; i < m + 1; i++)
    {
        b[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 0; i < m + 1; i++)
    {
        if (b[i] > 0)
        {
            c[i] = i;
        }
    }
    delete[] b;
    return c;
}
// ! to be fixed
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *b;
    b = removeDuplicates(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    delete[] b;
}