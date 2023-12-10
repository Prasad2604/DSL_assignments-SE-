#include<iostream>
using namespace std;
#define MAX_CAPACITY 20
class Stack{
    char stack[MAX_CAPACITY];
    int top;
    public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return (top==-1);
    }
    bool isFull(){
        return top==MAX_CAPACITY-1;
    }
    void push(char ch){
        if(isFull()){
            cout<<"Stack is full, can't push!!"<<endl;
        }
        else{
            stack[++top]=ch;
            // cout<<ch<<" added to stack.."<<endl;
        }
    }
    char pop(){
        if(isEmpty()){
            cout<<"Stack is empty, can't pop!!"<<endl;
            return ' ';
        } 
        else{
            int deleted_ele = stack[top];
            top--;
            // cout<<deleted_ele<<" poped from the stack.."<<endl;
            return deleted_ele;
        }   
    }
    void check_par(){
        string exp;
        cout<<"Enter expression to check :- ";
        cin>>exp;
        if(exp[0]==')'||exp[0]=='}'||exp[0]==']'){
                cout<<"expression is not well-parenthesized.."<<endl;
                return;
        }
        bool flag=0;
        for(int i=0;i<exp.length();i++){
            if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
                this->push(exp[i]);
            }
            else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
                char ch = this->pop();
                switch(exp[i]){
                    case ')':if(ch!='('){
                        flag=1;
                        break;
                    }
                    case '}':if(ch!='{'){
                        flag=1;
                        break;
                    }
                    case ']':if(ch!='['){
                        flag=1;
                        break;
                    }
                    default:cout<<"Invalid bracket!!"<<endl;
                }
            }
        }
        if(!flag && isEmpty()){
            cout<<"Expression is well-parenthesized"<<endl;
            return;
        }
        else{
            cout<<"Expression is not well-parenthesized"<<endl;

        }
    }
};

int main(){
    Stack s;
    s.check_par();
}