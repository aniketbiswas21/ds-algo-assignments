#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// * Displays the linked list
void displayLinkedList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

// * Adds a node to the end of the linked list
void append(Node **n, int value)
{
    Node *new_node = new Node();
    if (*n == NULL)
    {
        new_node->data = value;
        new_node->next = NULL;
        *n = new_node;
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    Node *head = *n;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = new_node;
}

// * Replaces the nodes position in between two indices i.e. source and destination
void replaceNode(Node **n, int source, int destination)
{
    Node *sourceNode = *n;
    Node *destinationNode = *n;
    Node *temp = NULL;
    Node *prevSource = NULL;
    Node *prevDestination = NULL;
    int count = 0;
    int count2 = 0;
    while (sourceNode != NULL)
    {
        if (count == source)
        {
            break;
        }
        prevSource = sourceNode;
        sourceNode = sourceNode->next;
        count++;
    }

    while (destinationNode != NULL)
    {
        if (count2 == destination)
        {
            break;
        }
        prevDestination = destinationNode;
        destinationNode = destinationNode->next;
        count2++;
    }

    if (sourceNode == NULL || destinationNode == NULL)
    {
        return;
    }

    if (prevSource != NULL)
    {
        prevSource->next = destinationNode;
    }
    else
    {
        *n = destinationNode;
    }

    if (prevDestination != NULL)
    {
        prevDestination->next = sourceNode;
    }
    else
    {
        *n = sourceNode;
    }
    Node *t = sourceNode->next;
    sourceNode->next = destinationNode->next;
    destinationNode->next = t;
}

// * Returns the current length of the linked list
int length(Node *n)
{
    int l = 0;
    while (n != NULL)
    {
        l++;
        n = n->next;
    }
    return l;
}

// * Transforms the list to the form of 0 being replaced by n
void transformList(Node **n)
{
    int l = length(*n);
    int startIndex = 0;
    int endIndex = l - 1;
    while (startIndex < endIndex)
    {
        replaceNode(n, startIndex++, endIndex--);
    }
}

int main()
{
    Node *n = new Node();
    n->data = 0;
    n->next = NULL;
    append(&n, 1);
    append(&n, 2);
    append(&n, 3);
    append(&n, 4);
    displayLinkedList(n);
    cout << endl;
    transformList(&n);
    cout << "After transforming the list: " << endl;
    displayLinkedList(n);
}