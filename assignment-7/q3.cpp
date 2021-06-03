#include <iostream>
using namespace std;

class HashTable
{
private:
    int size;
    int *HT;

public:
    HashTable(int s)
    {
        this->size = s;
        HT = new int[size];
        for (int i = 0; i < size; i++)
        {
            HT[i] = 0;
        }
    }
    // * Generates the hashing index for the incoming value
    int hash(int key)
    {
        return key % size;
    }
    // * Regenerates the hashing index using quadratic probing if the current hash index is already occupied
    int probe(int key)
    {
        int index = hash(key);
        int i = 0;
        while (HT[(index + (i * i)) % size] != 0)
        {
            i++;
        }
        return (index + (i * i)) % size;
    }

    // * Inserts a Value in the hashtable
    void insert(int key)
    {
        int index = hash(key);

        if (HT[index] != 0)
        {
            index = probe(key);
        }
        HT[index] = key;
    }

    // * Searches a Value in the hashtable
    int search(int key)
    {
        int index = hash(key);
        int i = 0;
        while (HT[(index + (i * i)) % size] != key)
        {
            if (index + (i * i) > size)
            {
                return -1;
            }
            i++;
        }

        return (index + (i * i)) % size;
    }

    // * Displays hashtable
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << HT[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    HashTable HT(10);
    int ch;
    int ans = 1;

    do
    {
        cout << "--Menu--" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted:" << endl;
            int element;
            cin >> element;
            HT.insert(element);
            break;
        case 2:
            cout << "Enter the element to be searched: " << endl;
            int key;
            cin >> key;
            if (HT.search(key) != -1)
            {

                cout << "Found value at : " << HT.search(key) << endl;
            }
            else
            {
                cout << "Could not find the given value" << endl;
            }
            break;
        case 3:
            HT.display();
            cout << endl;
            break;
        case 4:
            ans = 0;
            break;
        default:
            cout << "Please enter a valid input" << endl;
            break;
        }
    } while (ans == 1);
}