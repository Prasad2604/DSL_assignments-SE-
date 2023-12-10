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
    bool isFull(){
        return top==MAX_SIZE-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(char x){
        if(isFull()){
            cout<<"Stack is Full!!"<<endl;
        }
        else{
            top++;
            stack[top] = x;
        }
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack is empty!!"<<endl;
        }
        else{
            char ch = stack[top];
            top--;
            return ch;
        }
    }
    void display(){
        for(int i=top;i>-1;i--){
            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
    char getTop(){
        return stack[top];
    }
    


};

bool isOperator(char ch){
        return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')';
    }
    int prec(char ch){
        if(ch=='+'||ch=='-'){
            return 1;
        }
        else if(ch=='*'||ch=='/'){
            return 2;
        }
        else if(ch==')'){
            return 3;
        }
    }
    void convert(){
        string infix;
        cout<<"Infix : ";
        cin>>infix;
        Stack s;
        string postfix;
        for(int i=0;i<infix.length();i++){
            if(!isOperator(infix[i])){
                postfix+=infix[i];
            }
            else if(infix[i]==')'){
                while(s.getTop()!='('){
                    postfix+=s.pop();
                }
                s.pop();
            }
            else{
                if(s.isEmpty()){
                    s.push(infix[i]);
                }
                while(s.getTop()!='('||prec(infix[i])<=prec(s.getTop())){
                    postfix+=s.pop();
                }
                s.push(infix[i]);
            }
        }
        while(!s.isEmpty()){
            postfix+=s.pop();
        }
        cout<<"Postfix : "<<postfix<<endl;
    }
int main(){
    
    convert();
}