#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int max;
    int *A;

public:
    Stack(int max)
    {
        this->max = max;
        A = new int[max];
        top = -1;
    }

    // * Pushing an element at the very end of a stack
    void push(int value)
    {
        try
        {
            if (top >= max - 1)
            {
                throw -1;
            }
            A[top + 1] = value;
            top++;
        }
        catch (int x)
        {
            cout << "Stack is full, cannot push anymore elements" << endl;
        }
    }

    // * Popping an element from the very end of the stack
    void pop()
    {
        try
        {
            if (top == -1)
            {
                throw -1;
            }
            top--;
        }
        catch (int x)
        {
            cout << "Cannot pop from an empty stack" << endl;
        }
    }

    // * Check if a stack is full
    bool isFull()
    {
        if (top >= max - 1)
        {
            return true;
        }
        return false;
    }

    // * Check if a stack is empty
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

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
    // * Displays the stack in reverse
    void displayRev()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << A[i] << " ";
        }
    }
};

// * Q4(i)
// * Pushes element to a queue
void enqueue(Stack *s, int value)
{
    // * Pushing into the front stack
    s->push(value);
}

// * Q4(ii)
// * Removes an element from a queue
int dequeue(Stack *front, Stack *rear)
{
    try
    {
        if (front->isEmpty() && rear->isEmpty())
        {
            throw -1;
        }

        // * Moving all elements from front stack to rear stack
        if (rear->isEmpty())
        {
            while (!front->isEmpty())
            {
                rear->push(front->stackTop());
                front->pop();
            }
        }
        // * Capturing and popping the topmost element from rear stack
        int y = rear->stackTop();
        rear->pop();

        // * After popping, moving all the elements back to front stack from rear stack
        if (front->isEmpty())
        {
            while (!rear->isEmpty())
            {
                front->push(rear->stackTop());
                rear->pop();
            }
        }
        return y;
    }
    catch (int x)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
}

// * Q4(iii)
// * Checks if the queue is full or not
bool isQueueFull(Stack &front)
{
    // * Checks if the front stack is full or not
    return front.isFull();
}

// * Q4(iv)
// * Checks if the queue is empty or not
bool isQueueEmpty(Stack &front, Stack &rear)
{
    if (front.isEmpty() && rear.isEmpty())
    {
        return true;
    }
    return false;
}

// * Displays the queue
void displayQueue(Stack &s)
{
    s.displayRev();
}

int main()
{
    Stack front(10);
    Stack rear(10);
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
            enqueue(&front, num);
            break;
        case 2:
            cout << "Removing: " << dequeue(&front, &rear) << endl;
            break;
        case 3:
            if (isQueueFull(front) == true)
            {
                cout << "The queue is full" << endl;
            }
            else
            {
                cout << "The queue is not full" << endl;
            }
            break;
        case 4:
            if (isQueueEmpty(front, rear) == true)
            {
                cout << "The queue is empty" << endl;
            }
            else
            {
                cout << "The queue is not empty" << endl;
            }
            break;
        case 5:
            displayQueue(front);
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