#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

// * Q4(x)
void insertNode(Node **n, int value)
{
    Node *head = *n;
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    if (head != NULL)
    {

        while (head->next != NULL)
        {
            head = head->next;
        }
        head->next = newNode;
        newNode->prev = head;
    }
}
// * Q4(x)
void display(Node *n)
{
    Node *head = n;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *n1 = new Node();
    n1->data = 10;
    n1->next = NULL;
    n1->prev = NULL;
    insertNode(&n1, 20);
    insertNode(&n1, 30);
    insertNode(&n1, 40);
    display(n1);
}