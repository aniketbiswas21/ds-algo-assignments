#include <iostream>
using namespace std;

// * Sorts the incoming array in ascending order by making use of insertion sort
void insertionSort(int *a, int l)
{
    int i, key, j;
    for (i = 1; i < l; i++)
    {
        key = a[i];
        j = i - 1;

        // * Shifting the array elements till the key is smaller than the predecessor
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        // * assigning the position vacated after shifting to key
        a[j + 1] = key;
    }
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
    cout << "The initial array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    insertionSort(a, n);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}