#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool bracketsMatch(string s)
{
    stack<char> st;
    if (s.length() == 0)
    {
        return true;
    }
    if (s.length() == 1)
    {
        return false;
    }
    // * Return unbalanced expression if the starting index contains the following expressions
    if (s[0] == ')' || s[0] == ']' || s[0] == '}')
    {
        return false;
    }

    // * Iterate over the given string
    for (int i = 0; s[i] != '\0'; i++)
    {
        // * Push to the stack if starting brackets occur
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        // * If a closing bracket appears, check the top of the stack, if it doesn't correspond to the given closing bracket return false, else pop from the stack and continue
        else if (s[i] == ')')
        {
            if (st.top() != '(')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.top() != '[')
            {
                return false;
            }
            st.pop();
        }
        else if (s[i] == '}')
        {
            if (st.top() != '{')
            {
                return false;
            }
            st.pop();
        }
    }
    // * Returns true if the stack is empty => balanced paranthesis
    //  * Returns false if the stack is not empty => unbalanced paranthesis
    return st.empty();
}

int main()
{
    string s;
    cout << "Enter brackets input" << endl;
    cin >> s;
    if (bracketsMatch(s))
    {
        cout << "Parenthesis is balanced" << endl;
    }
    else
    {
        cout << "Parenthesis is not balanced" << endl;
    }
}