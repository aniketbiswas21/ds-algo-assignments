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

// * Sorts the incoming array in ascending order by making use of bubble sort
void bubbleSort(int *a, int l)
{
    bool notSwaped = 0;
    for (int i = 0; i < l - 1; i++)
    {
        notSwaped = 0;
        // * If no swapping took place in the inner loop that implies that the given array was already sorted therefore terminating the loop there and then
        if (notSwaped)
        {
            break;
        }
        for (int j = 0; j < l - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                notSwaped = 0;
            }
            else
            {

                notSwaped = 1;
            }
        }
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
    bubbleSort(a, n);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}