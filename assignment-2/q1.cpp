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

    int getLength()
    {
        return length;
    }

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

    int checkItem(int value)
    //  * created as a utility function, functionality same as linear search
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

    bool isArraySorted()
    {
        for (int i = 0; i < length - 1; i++)
        {
            if (A[i] > A[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    Array mergeArray(Array &arr2)
    {
        Array arr3(2 * (length + arr2.getLength()), length + arr2.getLength());
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            arr3.set(j++, A[i]);
        }
        for (int k = 0; k < arr2.getLength(); k++)
        {
            arr3.set(j++, arr2.get(k));
        }
        return arr3;
    }

    Array unionArr(Array &arr2)
    {
        Array arr3(2 * (length + arr2.getLength()), length + arr2.getLength());
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            arr3.set(j++, A[i]);
        }
        for (int i = 0; i < arr2.getLength(); i++)
        {
            if (arr3.checkItem(arr2.get(i)) == -1)
            {
                arr3.set(j++, arr2.get(i));
            }
        }
        return arr3;
    }

    Array intersectionArr(Array &arr2)
    {
        Array arr3(2 * (length + arr2.getLength()), length + arr2.getLength());
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (arr2.checkItem(A[i]) != -1)
            {
                arr3.set(j++, A[i]);
            }
        }
        return arr3;
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
    arr.display();
    // arr.append(20);
    // arr.insert(2, 100);
    // arr.deleteIndex(3);
    // arr.linearSearch(4);
    // arr.binarySearch(4);
    // cout << arr.get(5) << endl;
    // arr.set(1, 3);
    // arr.reverseArray();
    // arr.shift();
    Array arr2(10);
    arr2.create();
    arr2.display();
    // Array arr3 = arr.mergeArray(arr2);
    // Array arr3 = arr.unionArr(arr2);
    Array arr3 = arr.intersectionArr(arr2);

    arr3.display();
}