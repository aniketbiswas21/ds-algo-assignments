#include <iostream>
using namespace std;

int exceedGoal(int *a, int n, int goal)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if (sum > goal)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int g;
    cout << "enter goal" << endl;
    cin >> g;
    cout << exceedGoal(a, n, g) << endl;
}