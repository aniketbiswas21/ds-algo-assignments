// TODO
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// * Utility function to add a node to the very end of the linked list
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

void displayLinkedList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

void insertNode(Node **n, int index, int value)
{
    Node *new_node = new Node();
    Node *temp = *n;
    if (n == NULL)
    {
        return;
    }
    else if (index == 0)
    {
        new_node->data = value;
        new_node->next = temp;
        *n = new_node;
    }
    else
    {
        Node *prev = NULL;
        int current = 0;
        while (temp != NULL)
        {
            if (current == index)
            {
                break;
            }
            prev = temp;
            temp = temp->next;
            current++;
        }
        new_node->data = value;
        prev->next = new_node;
        new_node->next = temp;
    }
}

Node *insertionSort(Node *n)
{
    Node *sorted = new Node();
    Node *sortedHead = sorted;
    int index = 0;
    while (n != NULL)
    {
        index = 0;
        sorted = sortedHead;
        if (!sorted)
        {
            append(&sorted, n->data);
        }
        while (sorted != NULL)
        {
            if (n < sorted)
            {
                insertNode(&sorted, index - 1, n->data);
            }
            else if (n > sorted)
            {
                sorted = sorted->next;
            }
        }
    }

    return sorted;
}

int main()
{
    Node *n = new Node();
    append(&n, 1);
    append(&n, 3);
    append(&n, 2);
    append(&n, 6);
    append(&n, 5);
    displayLinkedList(n);
    Node *sortedList = insertionSort(n);
    displayLinkedList(sortedList);
}