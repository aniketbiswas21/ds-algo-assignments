// Hashing using chaining
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class HashTable
{
public:
    Node **HT;
    int size;

    HashTable(int size)
    {
        this->size = size;
        HT = new Node *[size];
        for (int i = 0; i < size; i++)
        {
            HT[i] = NULL;
        }
    }

    // * Generates the hashing index for the incoming value
    int hash(int key)
    {
        return key % 10;
    }

    // * Performing sorted insert on the hashtable
    void Insert(int key)
    {
        int hashIndex = hash(key);
        Node *newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;

        if (HT[hashIndex] == NULL)
        {
            HT[hashIndex] = newNode;
        }

        else
        {
            Node *prev = HT[hashIndex];
            Node *curr = HT[hashIndex];
            while (curr && curr->data < key)
            {
                prev = curr;
                curr = curr->next;
            }

            // * The element is found at the very first index
            if (prev == HT[hashIndex])
            {
                newNode->next = HT[hashIndex];
                HT[hashIndex] = newNode;
            }

            else
            {
                newNode->next = prev->next;
                prev->next = newNode;
            }
        }
    }

    // * Searches for a element in the hash table
    int Search(int value)
    {
        int hashIndex = hash(value);
        Node *h = HT[hashIndex];
        while (h)
        {
            if (h->data == value)
            {
                return h->data;
            }
            h = h->next;
        }

        return -1;
    }

    // * Deletes an element from the hash table
    void Delete(int value)
    {
        int hashIndex = hash(value);
        Node *h = HT[hashIndex];
        Node *n = NULL;

        // * Return if the element does not exist
        if (h == NULL)
        {
            return;
        }

        // * If the starting index is to be deleted
        if (h->data == value)
        {
            n = h->next;
            HT[hashIndex] = n;
            delete h;
            return;
        }

        while (h && h->data != value)
        {
            n = h;
            h = h->next;
        }

        n->next = h->next;
        delete h;
        return;
    }

    // * Displays the Hash Table
    void Display()
    {
        for (int i = 0; i < size; i++)
        {
            Node *n = HT[i];
            while (n != NULL)
            {
                cout << n->data << "-->";
                n = n->next;
            }
            cout << endl;
        }
    }

    ~HashTable()
    {
        for (int i = 0; i < size; i++)
        {
            Node *p = HT[i];
            while (HT[i])
            {
                HT[i] = HT[i]->next;
                delete p;
                p = HT[i];
            }
        }
        delete[] HT;
    }
};

int main()
{
    int n;
    cout << "Enter the size of HashTable" << endl;
    cin >> n;
    HashTable h(n);
    int ch;
    int ans = 1;
    do
    {
        cout << "--Menu--" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Display" << endl;
        cout << "4.Delete" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted:" << endl;
            int element;
            cin >> element;
            h.Insert(element);
            break;
        case 2:
            cout << "Enter the element to be searched: " << endl;
            int key;
            cin >> key;
            if (h.Search(key) != -1)
            {

                cout << "Found value: " << h.Search(key) << endl;
            }
            else
            {
                cout << "Could not find the given value" << endl;
            }
            break;
        case 3:
            h.Display();
            cout << endl;
            break;
        case 4:
            int val;
            cout << "Enter the value to be deleted" << endl;
            cin >> val;
            h.Delete(val);
            cout << endl;
            break;
        case 5:
            ans = 0;
            break;
        default:
            cout << "Please enter a valid input" << endl;
            break;
        }
    } while (ans == 1);
}