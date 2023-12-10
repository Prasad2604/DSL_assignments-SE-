#include<iostream>
using namespace std;

bool Operator(char c){
    return(c=='+'||c=='-'||c=='*'||c=='/');
}

int Precedence(char ch){
    if(ch=='+'|| ch=='-'){
        return 1;
    }
    else{
        return 2;
    }
    return 0;
}

string infix_to_postfix(string infix){
    string postfix="";
    for(char ch:infix){
        if(ch==' '){
            continue;
        }
        else if(Operator(ch)){
            
        }
    }
}