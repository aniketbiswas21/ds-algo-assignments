#include <iostream>
#include <stack>
#include <string>
using namespace std;

// * Returns true if the given input is an operator i.e. '+', '-', '*', '/' and '^'.
bool isOperator(char ch)
{
    return (!isalpha(ch) && !isdigit(ch));
}

// * Returns the priority assigned to a given operator
int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

// * Converts a given infix expression to postfix
string convertToPostfix(string s)
{
    // * Add parenthesis to the beginning and end of the infix expression
    s = '(' + s + ')';
    stack<char> st;
    string output;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isOperator(s[i]))
        {
            output += s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            if (isOperator(s[i]))
            {
                // * Removes the operator from stack, if the priority of the top is more(or equal) than the incoming character
                while ((getPriority(st.top()) > getPriority(s[i])) || (getPriority(s[i]) <= getPriority(st.top()) && s[i] == '^'))
                {
                    output += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    return output;
}

int main()
{
    string input;
    cout << "Enter an infix expression" << endl;
    getline(cin, input);
    cout << "The postfix expression is: " << endl;
    string output = convertToPostfix(input);
    cout << output;
}