#include<iostream>
using namespace std;

class Node{
    Node* next;
    int data;
    public:
    Node(){
        next=NULL;
        data=0;
    }
    Node(int data){
        next=NULL;
        this->data=data;
    }
    class List{
        Node* head;
        public:
        List(){
            head=NULL;
        }
        void append(int x){
            Node* p = new Node(x);
            Node* nptr = head;
            if(!head){
                head=p;
            }
            else{
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next = p;
            }
        }
        void display(){
            if(!head){
                cout<<"List is empty!!"<<endl;
            }
            else{
                Node* nptr=head;
                while(nptr->next){
                    cout<<nptr->data<<"->";
                    nptr = nptr->next;
                }
                cout<<nptr->data<<endl;
            }
        }
        void Union(List l1,List l2){
            Node* nptr = this->head;
            Node* nptr1 = l1.head;
            Node* nptr2 = l2.head;
            while(nptr1){
                this->append(nptr1->data);
                nptr1=nptr1->next;
            }
            while(nptr2){
                bool flag=0;
                nptr=this->head;
                while(nptr){
                    if(nptr2->data==nptr->data){
                        flag=1;
                        break;
                    }
                    nptr=nptr->next;
                }
                if(!flag){
                    this->append(nptr2->data);
                }
                nptr2=nptr2->next;
            }
            cout<<"Union is :- ";
            this->display();
        }
        void Intersection(List l1,List l2){
            Node* nptr=this->head;
            Node* nptr1 = l1.head;
            Node* nptr2 = l2.head;
            while(nptr1){
                bool flag=0;
                nptr2 = l2.head;
                while(nptr2){
                    if(nptr1->data==nptr2->data){
                        flag=1;
                        break;
                    }
                    nptr2 = nptr2->next;
                }
                if(flag){
                    this->append(nptr1->data);
                }
                nptr1=nptr1->next;
            }
            cout<<"Intersection is :- ";
            this->display();
        }
        void in_list(){
            int n;
            cout<<"Enter number of students :- ";
            cin>>n;
            while(n--){
                int x;
                cout<<"Enter roll no :- ";
                cin>>x;
                this->append(x);
                // this->display();
            }

        }
    };

};

int main(){
    Node::List l1,l2,l3,l4;
    // l1.display();
    l1.in_list();
    l1.display();
    l2.in_list();
    l2.display();
    l3.Union(l1,l2);
    l4.Intersection(l1,l2);


}