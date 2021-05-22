#include <iostream>
using namespace std;

// * Utility function to swap two numbers
void swap(int *i, int *j)
{
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}

// * Sorts the incoming array in ascending order by making use of selection sort
void selectionSort(int *a, int l)
{
    for (int i = 0; i < l - 1; i++)
    {
        // * Finding the smallest element in the remaining array
        int min_indx = i;
        for (int j = i + 1; j < l; j++)
        {
            if (a[min_indx] > a[j])
            {
                min_indx = j;
            }
        }
        // * Swapping the min element and the current element
        swap(&a[min_indx], &a[i]);
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
    selectionSort(a, n);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}