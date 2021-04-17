#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int max;

public:
    Stack()
    {
        top = NULL;
        this->max = 100;
    }

    // * Q1(i)
    // * Pushing an element at the very end of a stack
    void push(int value)
    {
        Node *n1;
        n1 = new Node();
        n1->data = value;
        n1->next = top;
        top = n1;
    }

    // * Q1(ii)
    // * Removing the topmost element from the stack
    void pop()
    {
        Node *temp = top;
        top = temp->next;
        delete temp;
    }

    // * Q1(iv)
    // * Check if a stack is empty or not
    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }

    // * Q1(v)
    // * Returns the topmost element in stack
    int peek()
    {
        if (top != NULL)
        {
            return top->data;
        }
        return -1;
    }

    // * Display the stack
    void display()
    {
        Node *n = top;
        while (n != NULL)
        {
            cout << n->data << " ";
            n = n->next;
        }
    }
};

int main()
{
    class Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.display();
    s.pop();
    cout << endl;
    s.display();
    cout << endl;
    if (s.isEmpty() == true)
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
    cout << s.peek() << endl;
}