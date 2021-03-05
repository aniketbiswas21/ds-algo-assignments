#include <bits/stdc++.h>
using namespace std;

int sum(int *a, int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s = s + a[i];
    }
    return s;
}

void input(int *a, int n)
{
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

int max(int *a, int l)
{
    int m = INT_MIN;
    for (int i = 0; i < l; i++)
    {
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    return m;
}
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

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *a = new int[n];
    input(a, n);
    int q = sum(a, n);
    cout << "The sum is:" << q << endl;
    int m = max(a, n);
    cout << "The maximum element is:" << m << endl;
    int key;
    cout << "Enter a key to find" << endl;
    cin >> key;
    int index = linearSearch(a, n, key);
    cout << "The element is found at:" << index << endl;
}