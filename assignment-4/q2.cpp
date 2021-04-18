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

    // * Q1(iii)
    // * Checks if the stack is full or not
    bool isFull(int l)
    {
        if (l >= max)
        {
            return true;
        }
        return false;
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

    // * Length of the stack
    int length()
    {
        Node *n = top;
        int l;
        while (n != NULL)
        {
            l++;
            n = n->next;
        }
        return l;
    }
};

int main()
{
    class Stack s;
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
        cout << "6.Display" << endl;
        cout << "7.Exit" << endl;
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
            if (s.isFull(s.length()) == true)
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
            cout << s.peek();
            cout << endl;
            break;
        case 6:
            s.display();
            cout << endl;
            break;
        case 7:
            ans = 0;
            break;
        default:
            cout << "Please enter a valid option" << endl;
            break;
        }
    } while (ans == 1);
}