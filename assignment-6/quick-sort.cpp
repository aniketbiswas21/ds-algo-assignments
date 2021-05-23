#include <iostream>
#include <limits.h>
using namespace std;

// * Utility function to swap two numbers
void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

// * Finding the partion index i.e. all the elements are smaller on the left and bigger on the right
int partition(int *a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

// * Sorts the incoming array in ascending order by making use of quick sort
void quickSort(int *a, int low, int high)
{
    if (low < high)
    {
        int j = partition(a, low, high);
        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
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
    quickSort(a, 0, n - 1);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}