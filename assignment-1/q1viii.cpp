#include <iostream>
using namespace std;

int *shiftRight(int *a, int n)
{
    int *b = new int[n];
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i + 1 >= n)
        {
            a[0] = b[i];
        }
        else
        {
            a[i + 1] = b[i];
        }
    }
    delete[] b;
    return a;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    shiftRight(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    delete[] arr;
}