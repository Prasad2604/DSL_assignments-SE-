#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Stack{
    char stack[MAX_SIZE];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool Operator(char ch){
        return (ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')');
    }
    int precedence(char ch){
        if(ch=='+'||ch=='-'){
            return 1;
        }
        else if(ch=='*'||ch=='/'){
            return 2;
        }
        else if(ch=='('){
            return 3;
        }
        return 0;
    }
    bool isFull(){
        return top==MAX_SIZE-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(char ch){
        if(isFull()){
            cout<<"Stack is full, can't push!!"<<endl;
        }
        else{
            stack[++top]=ch;
        }
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack is empty, can't pop!!"<<endl;
            return ' ';
        }
        else{
            char del_ele = stack[top];
            top--;
            return del_ele;
        }
    }
    char getTop(){
        return stack[top];
    }
    void display(){
        if(isEmpty()){
            cout<<"Nothing in stack!!"<<endl;
            return;
        }
        for(int i=0;i<top+1;i++){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    void infix_to_postfix(){
        string infix;
        cout<<"Infix : ";
        cin>>infix;
        string postfix;
        for(int i=0;i<infix.length();i++){
            if(isalnum(infix[i])){
                postfix+=infix[i];
            }
            // else if(Operator(infix[i])){
            else   if(isEmpty()){
                    this->push(infix[i]);
                    this->display();
                }
                else if(infix[i]=='('){
                    this->push(infix[i]);
                    this->display();
                }
                else if(infix[i]==')'){
                    while(this->pop()!='('){
                        postfix+=this->pop();
                    }
                    postfix+=this->pop();
                }
                else{
                    if(!this->isEmpty() && precedence(infix[i])<=precedence(stack[top]) && this->getTop()!='('){
                        postfix+=this->pop();
                        this->push(infix[i]);
                    }
                    else{
                        this->push(infix[i]);
                    }
                }
            // }
        }
        while(!this->isEmpty()){
            postfix+=this->pop();
        }
        cout<<"Postfix : "<<postfix<<endl;
    }

};
int main(){
    Stack s;
    s.infix_to_postfix();
}