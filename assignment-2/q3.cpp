#include <iostream>
using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;

public:
    Array(int size)
    {
        this->size = size;
        A = new int[size];
    }
    Array(int size, int length)
    {
        this->size = size;
        this->length = length;
        A = new int[size];
    }
    void create()
    {
        cout << "Enter number of elements: " << endl;
        cin >> length;
        cout << "Enter the array elements: " << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Array element: " << i << " = " << endl;
            cin >> A[i];
        }
    }
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int get(int index)
    {
        if (index > length || index < 0)
        {
            cout << "Enter a valid index" << endl;
            return -1;
        }
        return A[index];
    }

    void set(int index, int value)
    {
        if (index > length || index < 0)
        {
            cout << "Enter a valid index" << endl;
        }
        else
        {
            A[index] = value;
        }
    }
    // * Q3(i)
    int findSingleElements(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
    // * Q3(ii)
    void findMultipleElements(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == value)
            {
                cout << "The elements was found at: " << i << endl;
            }
        }
    }

    int max()
    {
        int m = A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i] > m)
            {
                m = A[i];
            }
        }
        return m;
    }
    // * Q3(vii)
    void minMax()
    {
        int m = A[0];
        int n = A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i] > m)
            {
                m = A[i];
            }
            if (A[i] < n)
            {
                n = A[i];
            }
        }
        cout << "The max element is: " << m << endl;
        cout << "The min element is: " << n << endl;
    }
    // * Q3(iii)
    // * Needs to have a sorted array as an input
    void findDuplicateElementSorted()
    {
        int prevDuplicate;
        for (int i = 0, j = i + 1; i < length - 1; i++)
        {

            if (A[i] == A[j] && prevDuplicate != A[i])
            {
                while (A[i] == A[j])
                {
                    prevDuplicate = A[i];
                    j++;
                }
                cout << A[i] << " repeats " << j - i << " times.";
                i = j;
            }
        }
    }
    // * Q3(iv)
    void findDuplicateElement()
    {
        int j = max();
        int *a = new int[j];
        for (int i = 0; i < j; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < length; i++)
        {
            a[A[i]]++;
        }
        for (int i = 0; i < j; i++)
        {
            if (a[i] > 1)
            {
                cout << i << " repeats " << a[i];
            }
        }
    }
    // * Q3(v)
    void pairSum(int sum)
    {
        int j = max();
        int *a = new int[j];
        for (int i = 0; i < j; i++)
        {
            a[i] = 0;
        }
        for (int i = 0; i < length; i++)
        {
            if (a[sum - A[i]] == 1)
            {
                cout << "Pair found: " << A[i] << " & " << sum - A[i] << endl;
                a[A[i]]++;
            }
            a[A[i]]++;
        }
    }
    // * Q3(vi)
    void pairSumSorted(int sum)
    {
        int i = 0;
        int j = length - 1;
        while (i < j)
        {
            if (A[i] + A[j] == sum)
            {
                cout << "Pair found: " << A[i] << " & " << A[j] << endl;
                i++;
                j--;
            }
            else if (A[i] + A[j] < sum)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
    }
};

int main()
{
    Array arr(10);
    arr.create();
    cout << "The initial array is:" << endl;
    arr.display();
    arr.minMax();
    // arr.pairSumSorted(10);
}