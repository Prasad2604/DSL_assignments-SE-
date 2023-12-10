#include<iostream>
using namespace std;

class Node{
    Node* next;
    Node* prev;
    int value;
    public:
    Node(){
        next=NULL;
        prev=NULL;
        value=0;
    }
    Node(int value){
        next=NULL;
        prev=NULL;
        this->value=value;
    }
    class List{
        Node* head;
        Node* tail;
        public:
        List(){
            head=NULL;
            tail=NULL;
        }
        void ins_start(int x){
            Node* p=new Node(x);
            if(!head){
                head = p;
                head->next = p;
                head->prev = p;
            }
            else{
      
                p->next = head;
                p->prev = head->prev;
               
                head->prev->next = p; 
                head->prev = p;
                head = p;
               
            }
        }
         void append(int val){
            Node* p = new Node(val);
            if(!head){
                head = p;
                head->next = p;
                head->prev = p;
                // p->next = head;
                // p->prev = head;
                // tail = p;
            }
            else{
                Node* nptr = head;
                while(nptr->next!=head){
                    nptr = nptr->next;
                }
                p->prev = nptr;
                p->next = nptr->next;
                nptr->next = p;
                head->prev = p;
               
                // cout<<tail->value<<endl;
            }
        }
        void display(){
            if(!head){
                cout<<"List is empty!!"<<endl;
            }
            else{
                Node* nptr = head;
                while(nptr->next!=head){
                    cout<<nptr->value<<"->";
                    nptr=nptr->next;
                }
                cout<<nptr->value<<endl;
            }
        }
        void con_binary(int x){
            // cout<<""
            int p = x;
            while(x){
                // cout<<x%2;
                this->ins_start(x%2);
                x=x/2;
            }
            cout<<endl;
            cout<<"Binary equivalent of "<<p<<" is :- ";
            this->display();
        }
        void find_1comp(){
            Node* nptr = head;
            cout<<"1's Compliment :- ";
            do{
                cout<<!(nptr->value)<<"->";
                nptr=nptr->next;
            }while(nptr->next!=head);
            cout<<!nptr->value<<endl;
            // cout<<endl;
        }
        void find_2comp(List *l1){
            int carry=1;
            Node* nptr1 = l1->head->prev;
            // cout<<nptr1->value;
            do{
                // cout<<"Hi"<<endl;
                this->ins_start(!nptr1->value^carry);
                // cout<<nptr1->value<<endl;
                carry = !nptr1->value&carry;
                // cout<<carry<<endl;
                nptr1 = nptr1->prev;
            }while(nptr1!=l1->head);
            this->ins_start(!nptr1->value^carry);
            if(carry){
                this->ins_start(carry);
            }
            cout<<"Two's Compliment :- ";
            this->display();
        }

        void bin_sum(List *l1,List *l2){
            int carry=0;
            Node* nptr1 = l1->head->prev;
            Node* nptr2 = l2->head->prev;
            do{
                cout<<"Hi"<<endl;
                this->ins_start(nptr1->value^nptr2->value^carry);
                carry = (carry&nptr1->value^nptr2->value)||(nptr1->value&nptr2->value);
                nptr1 = nptr1->prev;
                nptr2 = nptr2->prev;
            }while(nptr1!=l1->head && nptr2!=l2->head);
            do{
                cout<<"Helo"<<endl;
                this->ins_start(nptr1->value^carry);
                carry = carry&nptr1->value;
                nptr1=nptr1->prev;  
            }while(nptr1!=l1->head);
            while(nptr2!=l2->head){
                this->ins_start(nptr2->value^carry);
                carry = carry&nptr2->value;
                nptr2=nptr2->prev;  
            }
            if(carry){
                this->ins_start(carry);
            }
            this->display();
        }
    };
};

int main(){
    Node::List l1,l2,l3;
    l1.con_binary(5);
    l2.con_binary(1);
    l3.bin_sum(&l1,&l2);

    // l1.find_1comp();
    // l2.find_2comp(&l1);
}