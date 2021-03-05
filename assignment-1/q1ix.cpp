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

void removeDuplicates(int *a, int n)
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
    //  * pushing the elements that appear once to the left of array c
    int length = 0;
    for (int i = 0; i < m + 1; i++)
    {
        if (b[i] == 1)
        {
            c[length++] = i;
        }
    }
    //  * pushing the elements that appear more than once to the remainder of array c
    for (int i = 0; i < m + 1; i++)
    {
        if (b[i] > 0 && b[i] != 1)
        {
            c[length++] = i;
        }
    }
    // * displaying the computed array
    for (int i = 0; i < length; i++)
    {
        cout << c[i] << " ";
    }
    delete[] b;
    delete[] c;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    removeDuplicates(a, n);
    delete[] a;
}