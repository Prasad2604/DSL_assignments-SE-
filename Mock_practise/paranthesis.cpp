#include<iostream>
#include<string>
using namespace std;

class Stack{
    int capacity;
    char *S = new char(capacity);
    int top;
    public:
    Stack(){
        capacity=0;
        top=-1;
    }
    Stack(int capacity){
        this->capacity = capacity;
        top=-1;
    }
    bool isFull(){
        if(top==capacity-1){
            return 1;
        }
        return 0;
    }
    bool isEmpty(){
        if(top==-1){
            return 1;
        }
        return 0;
    }
    void push(char ch){
        if(!this->isFull()){
            S[++top]=ch;
            // cout<<S[top];
        }
        else{
            cout<<"can't push stack is full!!"<<endl;
        }
        
    }
    char pop(){
        if(!this->isEmpty()){
            return S[top--];
        }
        return '0';
        
    }
    


};
bool is_well_par(const string& s){
        Stack s1(s.size());
        for(char ch:s){
            // cout<<ch<<" ";
            if(ch=='('||ch=='{'||ch=='['){
                s1.push(ch);
            }
            else if (ch==')'||ch=='}'||ch==']'){
                if (s1.isEmpty()){
                    return false;  
                }
                char op = s1.pop();
                if((ch==')'&& op!='(')||(ch=='}'&& op!='{')||(ch==']'&& op!='[')){
                    return false;
                }

            }
            else{
                continue;
            }
        }
        return s1.isEmpty();
    }

int main(){
    string exp;
    cout<<"Enter the expression :- ";
    getline(cin,exp);
    if(is_well_par(exp)){
        cout<<"Expression is well-parenthesised"<<endl;
    }
    else{
        cout<<"Expression is not well-parenthesised"<<endl;
    }
    return 0;
}