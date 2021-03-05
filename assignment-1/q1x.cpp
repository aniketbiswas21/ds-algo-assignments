#include <iostream>
using namespace std;

int *merge(int *a, int n, int *b, int m)
{
    int *c = new int[n + m];
    for (int i = 0; i < n; i++)
    {
        c[i] = a[i];
    }
    for (int i = 0, j = n - 1; j < n + m; j++)
    {
        c[j] = b[i++];
    }
    return c;
}

void input(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    input(arr1, n);
    input(arr2, m);
    int *arr3;
    arr3 = merge(arr1, n, arr2, m);
    for (int i = 0; i < m + n - 1; i++)
    {
        cout << arr3[i] << " ";
    }
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}