#include <bits/stdc++.h>
using namespace std;

// * Returns the maximum element from an array
int max(int *arr, int w)
{
    int max = arr[0];
    for (int i = 0; i < w; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// * Runs a window of width w throughout the array
vector<int> slidingWindow(int *A, int l, int w)
{
    vector<int> res;
    int window[w];
    for (int i = 0; i <= l - w; i++)
    {
        int k = i;
        for (int j = 0; j < w; j++)
        {
            window[j] = A[k++];
        }
        int t = max(window, w);
        res.push_back(t);
    }
    return res;
}

int main()
{
    int n, w;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << "Enter the window size" << endl;
    cin >> w;
    int *A = new int[n];
    cout << "Enter the array items" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> result;
    result = slidingWindow(A, n, w);
    cout << "The answer is: " << endl;
    for (auto i = result.begin(); i != result.end(); ++i)
    {
        cout << *i << " ";
    }
}