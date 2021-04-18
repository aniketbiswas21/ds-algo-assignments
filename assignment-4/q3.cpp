#include <iostream>
using namespace std;

class Queue
{
private:
    int front = -1;
    int rear = -1;
    int size;
    int *A;

public:
    Queue(int size)
    {
        this->size = size;
        A = new int[size];
    }

    // * Q1(i)
    // * Adds an element to the rear end of the queue
    void enqueue(int value)
    {
        if (front == -1 && rear == -1)
        {
            A[0] = value;
            front++;
            rear++;
        }
        else if (rear >= size - 1)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            A[rear + 1] = value;
            rear++;
        }
    }

    // * Q2(ii)
    // * Removes an element from the beginning of list
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue underflow" << endl;
        }
        else
        {
            // * Shifting elements by one positon
            for (int i = 0; i <= rear; i++)
            {
                A[i] = A[i + 1];
            }
            rear--;
        }
    }

    // * Q2(iii)
    // * Checks if the queue is already full or not
    bool isFull()
    {
        if (rear >= size - 1)
        {
            return true;
        }
        return false;
    }

    // * Q2(iv)
    // * Checks if the queue is empty or not
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
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

    Queue q(10);
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
            q.dequeue();
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