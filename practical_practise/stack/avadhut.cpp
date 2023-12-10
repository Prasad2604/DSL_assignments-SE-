#include<iostream>
using namespace std;

class Stack{
    char s[100];
    int top;
    public:
    Stack(){
       
        top=-1;
    }
   
    void pushChar(char ch);
    char popChar();
    bool isEmpty();
    bool isFull();
    int priority(char ch);
    void infixtopostfix(char infix[], int size);
};

bool Stack::isEmpty(){
    if(top==-1) return true;
    else return false;
}
bool Stack::isFull(){
    if(top==99){
        return true;
    }
    else return false;
}
void Stack::pushChar(char ch){
    if (!isFull()){
        // top++;
        s[++top]=ch;
    }
}
char Stack::popChar(){
    if(!isEmpty()){
        char ch = s[top--];
        // top--;
        return ch;
    }
    else{
        return '\0';
    }
}

int Stack::priority(char ch){
    switch (ch){
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        // case '(':
        //     return 2;
        }
    return 0;
}

void Stack::infixtopostfix(char infix[] , int size){
    string ans = "";
    for (int i = 0; i < size; i++)
    {
        char ch = infix[i];
        if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            if(priority(ch)>priority(s[top]) || isEmpty()){
                pushChar(ch);
            }
            else{
                ans += s[top];
                s[top] = ch;
            }
        }
        // else if(ch=='(' ){
        //     cout << "bracket";
        //     pushChar(ch);
        // }
        // else if(ch==')' && !isEmpty()){
        //     while(s[top]!='('){
        //         ans += popChar();
        //     }
        //     popChar();
        // }
        else{
            ans += ch;
        }
    }
    while(!isEmpty()){
        ans += popChar();
    }
    cout <<endl<<"Postfix expression : "<< ans<<endl<<endl;
}

int main()
{
    // Stack st;
    // char exp[6] = "A+b-c";
    // st.infixtopostfix(exp, 6);
    Stack st;
    while(true){
        char *exp= new char;
        cout << "Enter an expression ==> ";
        cin >> exp;
        int i = 0, count = 0;
        cout << endl<< "Infix expression : ";
        while (exp[i] != '\0')
        {
            cout << exp[i];
            count++;
            i++;
        }

        st.infixtopostfix(exp, count);
        char ch;
        cout << "Do you want to continue (y/n) : ";
        cin >> ch;
        if(ch=='n' || ch=='N'){
            break;
        }
    }
}