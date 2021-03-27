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

    int getLength()
    {
        return length;
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
    // * Q2(ii)
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

    // * Q2(iii)
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
    cout << "The initial array 1 is:" << endl;
    arr.display();
    Array arr2(10);
    arr2.create();
    cout << "The initial array 2 is:" << endl;
    arr2.display();
    cout << "The union array is as follows: " << endl;
    Array arr3 = arr.unionArr(arr2);

    arr3.display();
    cout << endl;
    cout << "The intersection array is as follows: " << endl;
    Array arr4 = arr.intersectionArr(arr2);

    arr4.display();
    cout << endl;

    // Array arr3 = arr.mergeArray(arr2);
    // arr3.display();
    // arr.unionArrAlt(arr2);
    // arr.display();
}