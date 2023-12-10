#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    int priority;
    Node* next;
    Node(){
        data=0;
        priority=0;
        next=NULL;
    }
    Node(T data, int priority){
        this->data=data;
        this->priority=priority;
        this->next=NULL;
    }
    class PriorityQueue{
        Node* front;
        public:
        PriorityQueue(){
            front = NULL;
        }
        bool operator<=(const Node<T> &others)const{
            return priority<=others.priority;
        }
        void enqueue(T data,int priority){
            Node* p = new Node(data,priority);
            if(!front || priority>front->priority){
                p->next = front;
                front = p;
            }
            else{
                Node* nptr=front;
                while(nptr->next->priority>=priority && nptr->next){
                    nptr=nptr->next;
                }
                p->next = nptr->next;
                nptr->next = p;
            }
            cout<<"element enqueued"<<endl;
        }
        void dequeue(){
            if(!front){
                cout<<"Queue is empty"<<endl;
                return;
            }
            Node* nptr = front;
            front = front->next;
            cout<<"element with priority "<<nptr->priority<<" has been dequeued"<<endl;

        }
        void display(){
            if(!front){
                cout<<"Priority Queue is Empty!!"<<endl;
            }
            else{
                Node* nptr = front;
                while(nptr){
                    cout<<"Data :- "<<nptr->data<<" (Priority :- "<<nptr->priority<<')'<<endl;
                    nptr=nptr->next;
                }
            }
        }
    };
};

