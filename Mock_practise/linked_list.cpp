#include<iostream>
using namespace std;

class Node{
    Node* next;
    int value;
    public:
    Node(){
        next = NULL;
        value=0;
    }
    Node(int value){
        this->next=NULL;
        this->value=value;
    }

    class List{
        Node* head;
        public:
        List(){
            head=NULL;
        }
        void append(int x){
            if(!head){
                head = new Node(x);
            }
            else{
                Node* nptr=head;
                Node* p = new Node(x);
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next = p; 
            }
        }
        void ins_start(int x){
            if(!head){
                head=new Node(x);
            }
            else{
                Node* p = new Node(x);
                p->next = head;
                head = p;
            }
        }
        void del_start(){
            head = head->next;
        }
        void del_end(){
            Node* nptr= head;
            while(nptr->next->next){
                nptr=nptr->next;
            }
            nptr->next = NULL;
        }
        void display(){
            Node *nptr = head;
            if(!head){
                cout<<"List is empty insert something!!"<<endl;
            }
            else{
                while(nptr->next){
                    cout<<nptr->value<<"->";
                    nptr=nptr->next;
                }
                cout<<nptr->value<<endl;
            }
        }
    };
};

int main(){
    Node::List l1;
    l1.ins_start(5);
    l1.ins_start(10);
    l1.append(9);
    l1.display();
    l1.del_start();
    l1.display();
    l1.del_end();
    l1.display();
    l1.del_start();
    l1.display();
}