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

    //  TODO Add a menu driven program
    Queue q(10);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    q.dequeue();
    cout << endl;
    q.display();
    cout << endl;
    if (q.isEmpty() == false)
    {
        cout << "Not empty";
    }
}