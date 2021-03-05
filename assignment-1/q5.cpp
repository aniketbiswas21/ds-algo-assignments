#include <iostream>
using namespace std;

int linearSearch(int *a, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

void input(int *a, int n)
{
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *a = new int[n];
    input(a, n);
    int key;
    cout << "Enter a key to find" << endl;
    cin >> key;
    int index = linearSearch(a, n, key);
    cout << "The element is found at:" << index << endl;
}