#include <iostream>
#include <stack>
using namespace std;

class BST
{
public:
    int data;
    BST *left, *right;
    BST()
    {
        this->data = 0;
        left = NULL;
        right = NULL;
    }
    BST(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    // *  Q6, Q7
    // * Creates a new BST(if not existing)
    // * Inserts an element in the existing BST
    BST *insert(BST *root, int value)
    {
        // * Create a BST if not exist
        if (!root)
        {
            return new BST(value);
        }

        // * If the current element is greater than the root then move it to the right sub-tree
        if (value > root->data)
        {
            root->right = insert(root->right, value);
        }
        // * If the current element is less than the root then move it to the left sub-tree
        else
        {
            root->left = insert(root->left, value);
        }

        return root;
    }

    // * Q8
    // * Searches recursively for an element in BST
    bool recursiveSearchTree(BST *root, int val)
    {
        if (!root)
        {
            return false;
        }
        if (root->data == val)
        {
            cout << "Found " << val << endl;
            return true;
        }
        if (recursiveSearchTree(root->left, val) || recursiveSearchTree(root->right, val))
        {
            return true;
        }
    }

    // * Q8
    // * Searches iteratively for an element in BST
    bool iterativeSearchTree(BST *root, int val)
    {
        stack<BST *> st;
        BST *current = root;

        while (current != NULL || !st.empty())
        {
            while (current != NULL)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();

            if (current->data == val)
            {
                cout << "Found " << val << endl;
                return true;
            }
            current = current->right;
        }
        cout << "Not Found " << val << endl;
        return false;
    }

    // * Q9
    // * Inorder Traversal of BST
    void inorder(BST *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        cout << root->data << endl;
        inorder(root->right);
    }
};

int main()
{
    BST t, *root = NULL;
    cout << "Enter the size of the array: " << endl;
    int size;
    cin >> size;
    cout << "Enter the input array" << endl;
    int A[size];

    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    cout << "Inserted " << A[0] << endl;
    root = t.insert(root, A[0]);
    for (int i = 1; i < size; i++)
    {
        cout << "Inserted " << A[i] << endl;
        t.insert(root, A[i]);
    }
    cout << "Inorder Traversal of BST: " << endl;
    t.inorder(root);
    cout << endl;
    cout << "Enter an element to be searched: " << endl;
    int ele;
    cin >> ele;
    cout << "Recursively Searched: " << endl;
    t.recursiveSearchTree(root, ele);
    cout << "Iteratively Searched: " << endl;
    t.iterativeSearchTree(root, ele);
    return 0;
}