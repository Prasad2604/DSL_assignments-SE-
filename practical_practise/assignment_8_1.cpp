#include<iostream>
using namespace std;

class Node{
    Node* next;
    int in_time;
    int out_time;
    public:
    Node(){
        next = NULL;
        in_time=0;
        out_time=0;
    }
    Node(int in_time,int out_time){
        this->next=NULL;
        this->in_time=in_time;
        this->out_time=out_time;
    }
    class List{
        Node* head;
        public:
        List(){
            head=NULL;
        }
        bool is_Empty(){
            if(!head){
                return 1;
            }
            else{
                return 0;
            }
        }
        void ins_start(int in_time,int out_time){
            Node* p = new Node(in_time,out_time);
            if(!head){
                head=p;
            }
            else{
                p->next = head;
                head=p;
            }
        }
        void append(int in_time,int out_time){
            if(!head){
                head=new Node(in_time,out_time);
            }
            else{
                Node* nptr =head;
                Node* p = new Node(in_time,out_time);
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next=p;
            }
        }
        void display(Node* head){
            if(!head){
                cout<<"No slots available!!"<<endl;
            }
            else{
                Node* nptr = head;
                while(nptr){
                    cout<<nptr->in_time<<"-"<<nptr->out_time<<endl;
                    nptr=nptr->next;
                }
            }
        }
        void del(int intime,int outitme){
            Node* nptr = head;
            if(!head){
                cout<<"No slot available!!";
            }
            else{
                while(nptr->next){
                    if(nptr->next->in_time==intime){
                        nptr->next = nptr->next->next;
                    }
                    nptr=nptr->next;
                }
            }
        }
        void cancel(int intime,int outtime){
            Node* nptr=head;
            Node* p = new Node(intime,outtime);
            while(nptr->next->in_time<intime && nptr->next){
                nptr=nptr->next;
            }
            p->next = nptr->next;
            nptr->next = p;
        }
        Node* bubbleSortLinkedList(Node* head) {
            if (!head || !head->next) {
                // Empty or single-node list is already sorted
                return head;
            }

            Node* sortedList = nullptr;
            Node* end = nullptr;

            while (head->next != sortedList) {
                Node* current = head;
                while (current->next != end) {
                    Node* nextNode = current->next;
                    if (current->in_time > nextNode->in_time) {
                        // Swap the data of the current and nextNode
                        swap(current->in_time, nextNode->in_time);
                    }
                    current = current->next;
        
                // Move the end pointer to the last sorted element
                end = current;
            }

            return head;
        }
        }


        void appointment(){
            int n;
            cout<<"Enter number of slots you are available :- ";
            cin>>n;
            while(n--){
                int intime,outtime;
                cout<<"Enter intime :- ";
                cin>>intime;
                cout<<"Enter outtime :- ";
                cin>>outtime;
                this->append(intime,outtime);
            }
            head=this->bubbleSortLinkedList(this->head);
            this->display(head);
            
        }


        void book_app(){
            int a,b;
            cout<<"Enter intime :- ";
            cin>>a;
            cout<<"Enter outtime :- ";
            cin>>b;
            this->del(a,b);
            cout<<"Appontment booked successfully!!"<<endl;
        }
        void 
        


    };
};


int main(){
    cout<<"Enter slots"<<endl;
    Node::List l1;
    l1.appointment();
    cout<<"Available slots :- "<<endl;
    // l1.display();
    // l1.book_app();
    // l1.display();
}