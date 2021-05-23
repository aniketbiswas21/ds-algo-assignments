#include <iostream>
using namespace std;

// * Utility function to perform sorted merge
void merge(int *a, int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int B[high + 1];

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            B[k++] = a[i++];
        }
        else
        {
            B[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        B[k++] = a[i++];
    }

    while (j <= high)
    {
        B[k++] = a[j++];
    }

    for (int i = low; i <= high; i++)
    {
        a[i] = B[i];
    }
}

// * Sorts the incoming array in ascending order by making use of merge sort
void mergeSort(int *a, int low, int high)
{
    if (low < high)
    {
        // * Calculating the mid point of the array
        int mid = (low + high) / 2;
        // * Dividing the problem into two smaller sub-arrays
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        // * Performing sorted merge on the smaller problem(i.e. sub-array)
        merge(a, low, mid, high);
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
    mergeSort(a, 0, n - 1);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}