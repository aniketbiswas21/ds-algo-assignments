#include <iostream>
using namespace std;

int *reverseArray(int *a, int *b, int n)
{
    int i = 0;
    for (int j = n - 1; j >= 0; j--)
    {
        b[i++] = a[j];
    }
    return b;
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int *a2 = new int[n];
    a2 = reverseArray(a, a2, n);
    display(a2, n);
}