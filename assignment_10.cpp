#include <iostream>
#include <cctype>

using namespace std;

class Stack {
private:
    int capacity;
    int top;
    char* arr;

public:
    Stack(){
        capacity = 0;
        top = -1;

    }
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char value) {
        if (top == capacity - 1) {
            cerr << "Error: Stack Overflow" << endl;
            return;
        }
        arr[++top] = value;
    }

    char pop() {
        if (isEmpty()) {
            cerr << "Error: Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            cerr << "Error: Stack is empty" << endl;
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

class ExpressionConverter {
private:
    Stack operators;

    int precedence(char op) {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        return 0; // Assuming all other characters have lower precedence
    }

    int applyOperator(char op, int operand1, int operand2) {
        switch (op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default:
                cerr << "Error: Unexpected operator '" << op << "'" << endl;
                return 0;
        }
    }

public:
    ExpressionConverter() {}
    string infixToPostfix(const string& infix) {
        string postfix;
        for (char ch : infix) {
            if (isalnum(ch)) {
                postfix += ch;
            } else if (ch == '(') {
                operators.push(ch);
            } else if (ch == ')') {
                while (!operators.isEmpty() && operators.peek() != '(') {
                    postfix += operators.pop();
                }
                operators.pop();
            } else {
                while (!operators.isEmpty() && precedence(ch) <= precedence(operators.peek())) {
                    postfix += operators.pop();
                }
                operators.push(ch);
            }
        }

        while (!operators.isEmpty()) {
            postfix += operators.pop();
        }

        return postfix;
    }

    int evaluatePostfix(const string& postfix) {
        Stack operands(postfix.size());
        for (char ch : postfix) {
            if (isalnum(ch)) {
                operands.push(ch - '0');
            } else {
                int operand2 = operands.pop();
                int operand1 = operands.pop();
                int result = applyOperator(ch, operand1, operand2);
                operands.push(result);
            }
        }
        return operands.pop();
    }
};

int main() {
    ExpressionConverter converter;

    string infixExpression;
    cout << "Enter infix expression: ";
    getline(cin, infixExpression);

    string postfixExpression = converter.infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    int result = converter.evaluatePostfix(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
