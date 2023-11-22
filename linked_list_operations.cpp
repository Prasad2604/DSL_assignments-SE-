#include<iostream>
using namespace std;

class Node{
    private:
    int value;
    Node *next;
    public:
    Node(){
        value = 0;
        next = NULL;
    }
    Node(int value){
        this->value = value;
        next = NULL;
    }
    class list{
        private:
        Node* head;
        public:
        list(){
            head = NULL;
        }
        void ins_start(){
            int x;
            Node* p;
            Node* nptr;
            cout<<"Enter the value to insert :- ";
            cin>>x;
            if(!head){
                head = new Node(x);
            }
            else{
                p = new Node(x);
                nptr = head;
                p->next = nptr;
                head = p;
            }
        }

        void append(){
            int x;
            Node* p;
            Node* nptr;
            cout<<"Enter the value to insert :- ";
            cin>>x;
            if(!head){
                head = new Node(x);
            }
            else{
                p = new Node(x);
                nptr = head;
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next = p;
            }   
        }

        void display(){
            Node* nptr;
            if(!head){
                cout<<"Empty linked list"<<endl;
            }
            else{
                cout<<"List is :- "<<endl;
                nptr = head;
                while(nptr){
                    cout<<nptr->value<<" ";
                    nptr = nptr->next;
                }
                cout<<endl;
            }
        }

        void ins_at_pos(){
            int pos;
            cout<<"Enter element after which you want to insert data :- ";
            cin>>pos;
            int x;
            Node* p;
            Node* nptr;
            cout<<"Enter the value to insert :- ";
            cin>>x;
            if(!head){
                cout<<"list is empty"<<endl;
            }
            else{
                nptr = head;
                p = new Node(x);
                while(nptr->value!=pos){
                    nptr = nptr->next;
                }
                if(nptr->value==pos && nptr->next){
                    p->next = nptr->next;
                    nptr->next = p;
                }
                else if(nptr->value==pos){
                    nptr->next = p;
                }
                else{
                    cout<<"No such value exist"<<endl;
                }
            }
        }
    };
};

int main(){
    Node::list l;
    int ch;
    char ans = 'y';
    while(ans == 'y'){
        cout<<endl;
        cout<<"Choices \n 1.Insert at Start \n 2.Insert at end \n 3.display\n 4.Insert after partcular data\n"<<endl;
        cout<<"Enter choice :- ";
        cin>>ch;
        if(ch==1){
            l.ins_start();
        }
        else if(ch==2){
            l.append();
        }
        else if(ch==3){
            l.display();
        }
        else if(ch==4){
            l.ins_at_pos();
        }
        else{
            cout<<"Invalid choice"<<endl;
        }
        cout<<"Do you want to continue(y/n)?? :- ";
        cin>>ans;
    }
}