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
void countSort(int *a, int n)
{
    int max_inx = max(a, n);
    int *b = new int[max_inx + 1];

    // * assigning zero to all the elements of the new array
    for (int i = 0; i <= max_inx; i++)
    {
        b[i] = 0;
    }

    // * incrementing the values at position where element exists in the original array
    for (int i = 0; i < n; i++)
    {
        b[a[i]]++;
    }
    int i = 0;
    int j = 0;

    // * Copying back the elements to the original array if the current value in the new array is greater than 1
    while (i <= max_inx)
    {
        if (b[i] > 0)
        {
            a[j++] = i;
            b[i]--;
        }
        else
        {
            i++;
        }
    }
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
    countSort(a, n);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}