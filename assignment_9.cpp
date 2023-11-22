#include <iostream>
#include <string>

using namespace std;

class Stack {
private:
    char* arr;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(char element) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = element;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

bool isWellParenthesized(const string& expression) {
    Stack parenthesesStack(expression.size());

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            parenthesesStack.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (parenthesesStack.isEmpty()) {
                return false; 
            }

            char openBracket = parenthesesStack.pop();

            if ((ch == ')' && openBracket != '(') ||
                (ch == '}' && openBracket != '{') ||
                (ch == ']' && openBracket != '[')) {
                return false;  
            }
        }
    }

    return parenthesesStack.isEmpty(); 
}

int main() {
    string expression;

    cout << "Enter the expression: ";
    getline(cin, expression);

    if (isWellParenthesized(expression)) {
        cout << "The expression is well-parenthesized." << endl;
    } else {
        cout << "The expression is not well-parenthesized." << endl;
    }

    return 0;
}
