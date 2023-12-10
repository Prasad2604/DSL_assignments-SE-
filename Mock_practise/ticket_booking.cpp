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
        value = 0;
    }
    Node(int value){
        next=NULL;
        prev=NULL;
        this->value=value;
    }
    class TicketBooking{
        Node* head;
        Node* tail;
        public:
        TicketBooking(){
            head=NULL;
            tail = NULL;
        }
        void append(int val){
            Node* p = new Node(val);
            if(!head){
                head = p;
                p->next = head;
                p->prev = head;
                tail = p;
            }
            else{
                Node* nptr = head;
                while(nptr!=tail){
                    nptr = nptr->next;
                }
                p->next = nptr->next;
                nptr->next = p;
                tail = p;
                // cout<<tail->value<<endl;
            }
        }

        void add(){
            int seat;
            cout<<"Enter seat number for which you wanna cancel your booking :- ";
            cin>>seat;
            Node* nptr = head;
            while(nptr->next->value<seat){
                nptr=nptr->next;
            }
            Node* p = new Node(seat);
            p->next = nptr->next;
            p->prev = nptr;
            nptr->next->prev = p;
            nptr->next = p;
            
        }

        void display(){
            Node* nptr = head;
            while(nptr!=tail){
                cout<<nptr->value<<"->";
                nptr = nptr->next;
            }
            cout<<nptr->value<<endl;
            // cout<<endl;
        }
        void del(){
            int x;
            cout<<"Enter seat number which you wanna book :- ";
            cin>>x;
            Node* nptr = head;
            while(nptr->next->value!=x){
                nptr=nptr->next;
            }
            // nptr->prev->next = nptr->next;
            nptr->next = nptr->next->next;
            nptr->next->prev = nptr;
            // nptr->next->prev=nptr->prev;
        }
    };
};

int main(){
    // Node::TicketBooking t1;
    Node::TicketBooking t[10];
    for(int j=0;j<10;j++){
    for(int i=1;i<=7;i++){
        t[j].append(i);
    }
    }
    // t1.display();
    for(int j=0;j<10;j++){
        cout<<"Row "<<j+1<<" :- "  <<endl;
        t[j].display();
    }
    int a;
    cout<<"Enter row number in which you wanna book your seat :- "<<endl;
    cin>>a;
    t[a-1].del();
    cout<<"Updated seats :- "<<endl;
    t[a-1].display();
    cout<<"Enter row umber in which you want to cancel your booking :- ";
    int b;
    cin>>b;
    t[b-1].add();
    cout<<"Your ticket is cancled successfully!!"<<endl;
    cout<<"Updated seats :- "<<endl;
    t[b-1].display();

}