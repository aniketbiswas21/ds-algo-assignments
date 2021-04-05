#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int max;

public:
    int A[100];
    Stack()
    {
        top = -1;
        this->max = 100;
    }

    // * Q1(i)
    // * Pushing an element at the very end of a stack
    void push(int value)
    {
        if (top >= max - 1)
        {
            cout << "Stack is full, cannot push anymore elements" << endl;
            return;
        }
        A[top + 1] = value;
        top++;
    }

    // * Q1(v)
    // * Display the topmost element in stack
    int peek()
    {
        if (top < 0)
        {
            return -1;
        }
        return A[top];
    }

    // * Display the stack
    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << A[i] << " ";
        }
    }

    // * Q1(iii)
    // * Check if a stack is full
    bool isFull()
    {
        if (top >= max - 1)
        {
            return true;
        }
        return false;
    }

    // * Q1(iv)
    // * Check if a stack is empty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.peek() << endl;
    s.display();
    cout << endl;
    if (s.isFull() == true)
    {
        cout << "The stack is full" << endl;
    }
    else
    {
        cout << "The stack is not full" << endl;
    }

    if (s.isEmpty() == true)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
}