#include <iostream>
using namespace std;

// * Utility function to find the maximum element in the array
int max(int *a, int n)
{
    int val = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > val)
        {
            val = a[i];
        }
    }
    return val;
}

// * Sorts the incoming array in ascending order by making use of count sort
void countSort(int *a, int n, int e)
{
    int *b = new int[n];
    int count[10] = {0};
    int i;

    // * assigning zero to all the elements of the output array
    for (i = 0; i < n; i++)
    {
        b[i] = 0;
    }

        for (i = 0; i < n; i++)
    {
        count[(a[i] / e) % 10]++;
    }

    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; i--)
    {
        b[count[(a[i] / e) % 10] - 1] = a[i];
        count[(a[i] / e) % 10]--;
    }

    for (i = 0; i < n; i++)
    {

        a[i] = b[i];
    }
}

// * Sorts the incoming array in ascending order by making use of radix sort
void radixSort(int *a, int n)
{
    int m = max(a, n);

    // * Perform counting sort based on every digit in the number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *a = new int[n];
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "The initial array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    radixSort(a, n);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}