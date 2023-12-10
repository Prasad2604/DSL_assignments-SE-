#include<iostream>
using namespace std;

class Node{
    Node* next;
    int value;
    public:
    Node(){
        next=NULL;
        value=0;
    }
    Node(int x){
        next=NULL;
        value=x;
    }
    class List{
        Node* head;
        public:
        List(){
            head=NULL;
        }
        void append(int x){
            Node* p = new Node(x);
            if(!head){
                head=p;
            }
            else{
                Node* nptr=head;
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next=p;
            }
        }
        void Union(List &l1,List &l2){
            Node* nptr1 = l1.head;
            Node* nptr2 = l2.head;
            Node* nptr = this->head;
            while(nptr1){
                this->append(nptr1->value);
                nptr1 = nptr1->next;
            }
            while(nptr2){
                bool flag=0;
                while(nptr){
                    if(nptr2->value == nptr->value){
                        flag=1;
                        break;
                    }
                    nptr = nptr->next;
                }
                if(!flag){
                    this->append(nptr2->value);
                }
                nptr2 = nptr2->next;
            }
        }
        void intersection(List &l1,List &l2){
            Node* nptr1 = l1.head;
            Node* nptr2 = l2.head;
            Node* nptr = this->head;
            while(nptr1){
                bool flag=0;
                while(nptr2){
                    if(nptr1->value==nptr2->value){
                        flag=1;
                        break;
                    }
                    nptr2 = nptr2->next;
                }
                if(flag){
                    this->append(nptr1->value);
                }
                nptr1=nptr1->next;
                
            }
        }
        void display(string s){


            if(!head){
                cout<<"List is empty"<<endl;
            }
            else{
                cout<<s<<" list :- ";
                Node* nptr = this->head;
                while(nptr->next){
                    cout<<nptr->value<<"->";
                    nptr=nptr->next;
                }
                cout<<nptr->value<<endl;
            }
        }
        void in_list(string s){
            int n;
            // cout<<"Enter total number of student :- ";
            
            cout<<"Total number of students who like "<<s<<":- ";
            cin>>n;
            while(n--){
                int x;
                cout<<"Enter roll number of students who like "<<s<<" :- ";
                cin>>x;
                this->append(x);
            }
        }
    };  
};

int main(){
    Node::List l1,l2,l3,l4;
    l1.in_list("Vanilla Ice-cream");
    cout<<endl;
    l1.display("Vanilla Ice-cream");
    cout<<endl;
    l2.in_list("Butterscotch Ice-cream");
    cout<<endl;
    l2.display("Butterscotch Ice-cream");
    cout<<endl;
    l3.intersection(l1,l2);
    cout<<endl;
    l3.display("Intersection");
    cout<<endl;
    l4.Union(l1,l2);
    cout<<endl;
    l4.display("Union");
    cout<<endl;
    

}