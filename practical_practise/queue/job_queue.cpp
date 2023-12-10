#include<iostream>
using namespace std;
#define MAX_SIZE 100
class Queue{
    int queue[MAX_SIZE];
    int front;
    int rear;
    public:
    Queue(){
        front=rear=-1;
    }
    bool isFull(){
        return rear==MAX_SIZE-1;
    }
    bool isEmpty(){
        return (front==-1||front>rear);
    }
    void add(int job){
        if(isFull()){
            cout<<"Queue is full, can't add new job!!"<<endl;
            return;
        }
        if(front==-1){
            front++;
        }
        queue[++rear]=job;
        cout<<"front : "<<front<<" rear : "<<rear<<endl;
        cout<<job<<" added to queue!!"<<endl;
    }
    void del(){
        if(isEmpty()){
            cout<<"Queue is empty, can't delete job!!"<<endl;
            return;
        }
        int deleted_ele = queue[front++];
        cout<<"front : "<<front<<" rear : "<<rear<<endl;
        if(front>rear){
            front=rear=-1;
        }
        cout<<deleted_ele<<" deleted from queue!!"<<endl;
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty!!"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    Queue q;
    q.add(1);
    q.add(3);
    q.display();
    q.del();
    q.display();
    q.del();
    q.display();
}