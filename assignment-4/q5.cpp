#include <iostream>
#include <algorithm>
using namespace std;

// * Finds the maximum element's index
int findMax(int A[], int n)
{
    int max = A[0];
    int index = 0;
    for (int i = 0; i <= n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
            index = i;
        }
    };
    return index;
};

class PrQueue
{
public:
    int size;
    int *A;
    int rear;

    PrQueue(int n)
    {
        size = n;
        A = new int[size];
        rear = -1;
    };

    // * Q5(i)
    // * Inserts an element in the priority queue
    void enqueue(int x)
    {
        rear++;
        A[rear] = x;
    };

    // * Q5(ii)
    // * Removes an element(the maximum) from the priority queue
    int dequeue()
    {
        int x;
        int index = findMax(A, rear);
        for (int i = index; i < rear; i++)
        {
            swap(A[i], A[i + 1]);
        };
        cout << endl;
        x = A[rear];
        A[rear] = 0;
        rear--;
        return x;
    };

    // * Q5(iii)
    // * Checks if the queue is full or not
    bool isFull()
    {
        if (rear >= size - 1)
        {
            return true;
        }
        return false;
    }

    // * Q5(iv)
    // * Checks if the queue is empty or not
    bool isEmpty()
    {
        if (rear == -1)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i <= rear; i++)
        {
            cout << A[i] << " ";
        }
    }
};

int main()
{
    PrQueue q(5);
    int ch;
    int ans = 1;
    do
    {
        cout << "--Menu--" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.isFull" << endl;
        cout << "4.isEmpty" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            int num;
            cout << "Enter a number to insert" << endl;
            cin >> num;
            q.enqueue(num);
            break;
        case 2:
            cout << q.dequeue() << " was removed" << endl;
            break;
        case 3:
            if (q.isFull() == true)
            {
                cout << "The queue is full" << endl;
            }
            else
            {
                cout << "The queue is not full" << endl;
            }
            break;
        case 4:
            if (q.isEmpty() == true)
            {
                cout << "The queue is empty" << endl;
            }
            else
            {
                cout << "The queue is not empty" << endl;
            }
            break;
        case 5:
            q.display();
            cout << endl;
            break;
        case 6:
            ans = 0;
            break;
        default:
            cout << "Please enter a valid option" << endl;
            break;
        }
    } while (ans == 1);
}