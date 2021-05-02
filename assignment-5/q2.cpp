#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

// * Creates a new node
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// * adds a node to the very end of the linked list
void append(Node **n, int value)
{
    Node *new_node = new Node;
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

// * Reverses a linked list
void reverselist(Node **n)
{
    Node *prev = NULL, *curr = *n, *next;

    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *n = prev;
}

// * displays the linked list
void displayList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        if (n->next)
            cout << "-> ";
        n = n->next;
    }
    cout << endl;
}

// * Transforma a Linked List to the form of {A1, An, A2, An-1...}
void transform(Node **n)
{
    //  * Finding the middle point of the linked list so as to break it in two lists
    Node *slow = *n, *fast = slow->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // * Splits the list
    Node *head1 = *n;
    Node *head2 = slow->next;
    slow->next = NULL;

    // * Reverses list 2
    reverselist(&head2);

    *n = newNode(0);

    Node *curr = *n;
    // * Merge elements from the two lists in alternate manner
    while (head1 || head2)
    {
        // * adds a element from list1
        if (head1)
        {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }

        // * adds a element from list2
        if (head2)
        {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    // * Assign the head of the new list generated to head pointer
    *n = (*n)->next;
}

int main()
{
    Node *head = newNode(12);
    append(&head, 24);
    append(&head, 36);
    append(&head, 48);
    append(&head, 60);
    cout << "The original list is: " << endl;
    displayList(head);
    cout << "Modified list is: " << endl;
    transform(&head);
    displayList(head);
    return 0;
}