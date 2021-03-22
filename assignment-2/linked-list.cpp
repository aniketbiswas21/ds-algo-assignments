#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void displayLinkedList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void countSumNode(Node *n)
{
    int sum = 0;
    int count = 0;
    while (n != NULL)
    {
        sum = sum + n->data;
        count++;
        n = n->next;
    }
    cout << "The sum is: " << sum << endl;
    cout << "The count is: " << count << endl;
}

int searchNode(Node *n, int value)
{
    int index = 0;
    while (n != NULL)
    {
        if (n->data == value)
        {
            return index;
        }
        n = n->next;
        index++;
    }
    return -1;
}

int main()
{
    Node *n1;
    Node *n2;
    Node *n3;
    Node *n4;

    n1 = new Node();
    n2 = new Node();
    n3 = new Node();

    n1->data = 1;
    n1->next = n2;

    n2->data = 2;
    n2->next = n3;

    n3->data = 3;
    n3->next = NULL;

    displayLinkedList(n1);
    countSumNode(n1);
    cout << "Element found at: " << searchNode(n1, 3) << endl;
}