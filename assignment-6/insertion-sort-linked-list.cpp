#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class list
{
    Node *head;

public:
    list()
    {
        head = NULL;
    }

    void add(int el)
    {
        Node *newNode = new Node();

        newNode->data = el;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // * Sorts the incoming array in ascending order by making use of insertion sort
    void insertionSort()
    {
        Node *i = head->next;

        while (i != NULL)
        {
            Node *key = i;
            Node *j = head;

            while (j != i)
            {
                if (key->data < j->data)
                {
                    int temp = key->data;
                    key->data = j->data;
                    j->data = temp;
                }
                j = j->next;
            }
            i = i->next;
        }
    }

    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main()
{
    list l;
    l.add(21);
    l.add(11);
    l.add(0);
    l.add(3);
    l.add(70);
    l.add(42);

    l.insertionSort();
    cout << "The sorted list is: " << endl;
    l.display();
}