#include <iostream>
#include <stack>
#include <string>
using namespace std;

// * Evaluates a given postfix expression
int evaluate(string s)
{
    stack<int> st;
    int output;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        // * pushes to the stack if it is a operand
        else if (isdigit(s[i]))
        {
            int num = 0;

            // * extracts the full number say '100' as 100
            while (isdigit(s[i]))
            {
                num = num * 10 + (int)(s[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
        else
        {
            bool secondExists = false;
            int num1 = st.top();
            st.pop();
            int num2;
            // * Checks if the stack is empty after popping one number
            if (!st.empty())
            {
                num2 = st.top();
                st.pop();
                secondExists = true;
            }

            if (s[i] == '+')
            {
                if (secondExists)
                {
                    output = num1 + num2;
                }
                else
                {
                    output = num1;
                }
                st.push(output);
            }

            else if (s[i] == '-')
            {
                if (secondExists)
                {
                    output = num2 - num1;
                }
                else
                {
                    output = num1;
                }
                st.push(output);
            }

            else if (s[i] == '*')
            {
                if (secondExists)
                {
                    output = num2 * num1;
                }
                else
                {
                    output = num1;
                }
                st.push(output);
            }
            else if (s[i] == '/')
            {
                if (secondExists)
                {
                    output = num2 / num1;
                }
                else
                {
                    output = num1;
                }
                st.push(output);
            }
            else if (s[i] == '^')
            {
                if (secondExists)
                {
                    output = num2 ^ num1;
                }
                else
                {
                    output = num1;
                }
                st.push(output);
            }
        }
    }
    // * Return the only remaining element as the answer
    int res = st.top();
    st.pop();
    return res;
}

int main()
{
    string input;
    cout << "Enter a postfix expression" << endl;
    getline(cin, input);
    cout << "The answer is: " << evaluate(input) << endl;
}