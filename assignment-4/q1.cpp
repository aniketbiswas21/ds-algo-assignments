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

    // * Q1(ii)
    // * Popping an element from the very end of the stack
    void pop()
    {
        if (top == -1)
        {
            cout << "Cannot pop from an empty stack" << endl;
            return;
        }
        top--;
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

    // * Q1(v)
    // * Displays an element with index respect to top
    // * Eg: peek(2) => displays the 2nd index from the top. Considering top as the 0th index
    int peek(int index)
    {
        if (top < 0)
        {
            cout << "Cannot peek onto an empty stack" << endl;
            return -1;
        }
        int findIndex = top - index;
        for (int i = 0; i < top; i++)
        {
            if (i == findIndex)
            {
                return A[i];
            }
        }
        return -1;
    }

    // * Q1(vi)
    // * Display the topmost element in stack
    int stackTop()
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
        for (int i = top; i >= 0; i--)
        {
            cout << A[i] << " ";
        }
    }
};

int main()
{
    class Stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // s.push(5);

    // cout << s.stackTop() << endl;
    // s.display();
    // cout << endl;
    // if (s.isFull() == true)
    // {
    //     cout << "The stack is full" << endl;
    // }
    // else
    // {
    //     cout << "The stack is not full" << endl;
    // }

    // if (s.isEmpty() == true)
    // {
    //     cout << "The stack is empty" << endl;
    // }
    // else
    // {
    //     cout << "The stack is not empty" << endl;
    // }
    // s.pop();
    // s.display();
    // cout << endl;
    // cout << s.peek(3) << endl;

    int ch;
    int ans = 1;
    do
    {
        cout << "--Menu--" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.isFull" << endl;
        cout << "4.isEmpty" << endl;
        cout << "5.Peek" << endl;
        cout << "6.StackTop" << endl;
        cout << "7.Display" << endl;
        cout << "8.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            int num;
            cout << "Enter a number to insert" << endl;
            cin >> num;
            s.push(num);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            if (s.isFull() == true)
            {
                cout << "The stack is full" << endl;
            }
            else
            {
                cout << "The stack is not full" << endl;
            }
            break;
        case 4:
            if (s.isEmpty() == true)
            {
                cout << "The stack is empty" << endl;
            }
            else
            {
                cout << "The stack is not empty" << endl;
            }
            break;
        case 5:
            int index;
            cout << "Enter an index" << endl;
            cin >> index;
            cout << s.peek(index);
            cout << endl;
            break;
        case 6:
            s.stackTop();
            cout << endl;
            break;
        case 7:
            s.display();
            cout << endl;
            break;
        case 8:
            ans = 0;
            break;
        default:
            cout << "Please enter a valid option" << endl;
            break;
        }
    } while (ans == 1);
}