#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// * Q4(i)
void displayLinkedList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}

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

// * Q4(ii)
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

// * Q4(iii)
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

// * Q4(iv)
void deleteNode(Node **n, int key)
{

    Node *temp = *n;
    Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *n = temp->next;
        delete temp;
        return;
    }

    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        prev->next = temp->next;
        delete temp;
    }
}

// * Q4(v)
bool isSortedList(Node *n)
{
    if (n == NULL)
    {
        return true;
    }

    while (n->next != NULL)
    {
        if (n->data > n->next->data)
        {
            return false;
        }
        n = n->next;
    }
    return true;
}
// * Q4(vi)
// * Takes in two sorted linked list and merges them in a sorted manner.
Node *mergeList(Node *l, Node *m)
{
    Node *n = new Node();
    while (l->next != NULL && m->next != NULL)
    {
        if (l->data < m->data)
        {
            append(&n, l->data);
            l = l->next;
        }
        else if (l->data > m->data)
        {
            append(&n, m->data);
            m = m->next;
        }
        else
        {
            append(&n, l->data);
            l = l->next;
            m = m->next;
        }
    }
    while (l != NULL)
    {
        append(&n, l->data);
        l = l->next;
    }

    while (m != NULL)
    {
        append(&n, m->data);
        m = m->next;
    }
    return n;
}

// * Q4(vii)
// * Appends another linked list at the end of the previous linked list.
// * Appends m to l
void concatenateList(Node **l, Node **m)
{
    Node *head1 = *l;
    while (head1->next != NULL)
    {
        head1 = head1->next;
    }
    head1->next = *m;
}
// * Q4(viii)
void reverseLinkedList(Node **n)
{
    Node *prev = NULL;
    Node *current = *n;
    Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *n = prev;
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
    // append(&n1, 10);
    displayLinkedList(n1);
    cout << endl;
    // countSumNode(n1);
    // cout << "Removing 3: " << endl;
    // cout << "Element found at: " << searchNode(n1, 3) << endl;

    // deleteNode(&n1, 3);
    // displayLinkedList(n1);

    // displayLinkedList(n1);
    cout << endl;
    // if (isSortedList(n1) == 1)
    // {
    //     cout << "true" << endl;
    // }
    // else
    // {
    //     cout << "false" << endl;
    // }
    // cout << isSortedList(n1) << endl;

    // Node *h1 = new Node();
    // h1->data = 30;
    // h1->next = NULL;
    // append(&h1, 40);
    // append(&h1, 50);
    // append(&h1, 60);
    // append(&h1, 80);

    // displayLinkedList(h1);
    // cout << endl;
    // concatenateList(&n1, &h1);
    // cout << "Concated list is as follows: " << endl;
    // displayLinkedList(n1);

    // Node *l1 = mergeList(n1, h1);
    // cout << endl;
    // cout << "Merged list is as follows: " << endl;
    // displayLinkedList(l1);
    reverseLinkedList(&n1);
    // cout << endl;
    displayLinkedList(n1);
}