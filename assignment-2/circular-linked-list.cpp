#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void circularAppend(Node **n, int value)
{
    Node *head = *n;
    Node *newNode = new Node();
    if (head == NULL)
    {
        newNode->data = value;
        newNode->next = newNode;
        head = newNode;
    }
    else if (head != NULL)
    {
        while (head->next != *n)
        {
            head = head->next;
        }
        newNode->data = value;
        head->next = newNode;
        newNode->next = *n;
    }
}

void displayCircularLinkedList(Node *n)
{
    Node *temp = n;
    if (n != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != n);
    }
}

int main()
{
    Node *n1 = new Node();
    n1->data = 10;
    n1->next = n1;
    circularAppend(&n1, 10);
    circularAppend(&n1, 20);
    circularAppend(&n1, 30);
    displayCircularLinkedList(n1);
}