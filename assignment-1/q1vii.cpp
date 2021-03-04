#include <bits/stdc++.h>
using namespace std;

int max(int *a, int l)
{
    int m = INT_MIN;
    int index;
    for (int i = 0; i < l; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    int n;
    cout << "Enter the length of array" << endl;
    cin >> n;
    cout << "Enter the elements of the array" << endl;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The max element's index is:" << max(a, n) << endl;
    delete[] a;
}