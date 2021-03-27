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
    // * Q1(i)
    void display()
    {
        for (int i = 0; i < length; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int getLength()
    {
        return length;
    }

    // * Q1(ii)
    void append(int value)
    {
        if (size <= length)
        {
            cout << "Cannot add more elements" << endl;
        }
        else
        {
            A[length] = value;
            length++;
        }
    }

    // * Q1(iii)
    void insert(int index, int value)
    {
        if (index < 0 || index > length)
        {
            cout << "Enter a valid index" << endl;
        }
        else
        {
            for (int j = length - 1; j >= index; j--)
            {
                A[j + 1] = A[j];
            }
            length++;
            A[index] = value;
        }
    }

    // * Q1(iv)
    void deleteIndex(int index)
    {
        if (index > length || index < 0)
        {
            cout << "Enter a valid index" << endl;
        }
        else
        {
            for (int i = index; i < length; i++)
            {
                A[i] = A[i + 1];
            }
            length--;
        }
    }

    // * Q1(v)
    void linearSearch(int value)
    {
        for (int i = 0; i < length; i++)
        {
            if (A[i] == value)
            {
                cout << "Found at: " << i << endl;
                return;
            }
        }
        cout << "Does not exist" << endl;
    }

    // * Q1(vi)
    void binarySearch(int value)
    {
        int low = 0;
        int high = length - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (A[mid] == value)
            {
                cout << "Found at: " << mid << endl;
                return;
            }
            else if (A[mid] > value)
            {
                high = mid - 1;
            }
            else if (A[mid] < value)
            {
                low = mid + 1;
            }
        }
        cout << "Not Found" << endl;
    }

    //  * created as a utility function, functionality same as linear search
    int checkItem(int value)
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
    // * Q1(vii)
    int get(int index)
    {
        if (index > length || index < 0)
        {
            cout << "Enter a valid index" << endl;
            return -1;
        }
        return A[index];
    }

    // * Q1(viii)
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
    // * Q1(ix)
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
    // * Q1(x)
    int min()
    {
        int m = A[0];
        for (int i = 0; i < length; i++)
        {
            if (A[i] < m)
            {
                m = A[i];
            }
        }
        return m;
    }
    // * Q1(xi)
    void reverseArray()
    {
        int *B = new int[length];
        for (int i = length - 1, j = 0; i >= 0; i--)
        {
            B[j++] = A[i];
        }
        for (int i = 0; i < length; i++)
        {
            A[i] = B[i];
        }
        delete[] B;
    }
    // * Q1(xiii)
    void rotate()
    {
        int *b = new int[length];
        for (int i = 0; i < length; i++)
        {
            b[i] = A[i];
        }
        for (int i = 0; i < length; i++)
        {
            if (i == length - 1)
            {
                A[0] = b[i];
            }
            else
            {
                A[i + 1] = b[i];
            }
        }
        delete[] b;
    }
    // * Q1(xii)
    void shift()
    {
        int *b = new int[length];
        for (int i = 0; i < length; i++)
        {
            b[i] = A[i];
        }
        for (int i = 0; i < length; i++)
        {
            if (i == length - 1)
            {
                A[0] = 0;
            }
            else
            {
                A[i + 1] = b[i];
            }
        }
        delete[] b;
    }

    ~Array()
    {
        delete[] A;
        cout << "Array destroyed" << endl;
    }
};

int main()
{
    Array arr(10);
    arr.create();
    cout << "The initial array: " << endl;
    arr.display();
    // cout << "The element at index 2 is:" << arr.get(2);
    // cout << "The min elem is:" << arr.min();
    arr.rotate();
    arr.display();

    // arr.insert(2, 100);
    // arr.deleteIndex(3);
    // arr.linearSearch(4);
    // arr.binarySearch(4);
    // cout << arr.get(5) << endl;
    // arr.set(1, 3);
    // arr.reverseArray();
    // arr.shift();
    // Array arr2(10);
    // arr2.create();
    // arr2.display();
}