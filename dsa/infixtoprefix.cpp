#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) { // If operand, add to postfix expression
            postfix += c;
        } else if (c == '(') { // If opening parenthesis, push to stack
            s.push(c);
        } else if (c == ')') { // If closing parenthesis, pop and add to postfix until opening parenthesis is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Discard the opening parenthesis
        } else { // If operator, pop and add to postfix until a lower precedence operator is found
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Pop remaining operators from stack and add to postfix
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix_expression;
    cout << "Enter infix expression: ";
    getline(cin, infix_expression);

    string postfix_expression = infixToPostfix(infix_expression);
    cout << "Postfix expression: " << postfix_expression << endl;


    return 0;
}

