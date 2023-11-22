#include<iostream>
using namespace std;

class Node{
    private:
    int value;
    Node *next;
    public:
    Node(){
        value=0;
        next = NULL;
    }
    Node(int value){
        this->value=value;
        next = NULL;
    }

    class List{
        private:
        Node *head;
        public:
        List(){
            head =NULL;
        }
        void append(){
            Node *p;
            Node *nptr;
            int x;
            cout<<"Enter value you want to input :- "<<" ";
            cin>>x;

            if(!head){
                head = new Node(x);
            }
            else{
                p=new Node(x);
                nptr = head;
                while(nptr->next){
                    nptr=nptr->next;
                }
                nptr->next = p;

            }
        }
        void Input(){
            int n;
            cout<<"Enter number of students :- "<<" ";
            cin>>n;
            for(int i=0;i<n;i++){
                append();
            }
            
        }

        void display(){
            if(!head){
                cout<<"List is empty!!"<<endl;
            }
            else{
                Node *nptr;
                nptr = head;
                // cout<<endl;
                cout<<"List is :- "<<endl;
                while(nptr){
                    cout<<nptr->value<<" ";
                    nptr = nptr->next;
                }
                cout<<endl;
            }
        }
        void intersection(List &L1, List &L2){
            List L3;
            Node *nptr1 = L1.head;
            Node *nptr2 = L2.head;
            Node *nptr = L3.head;
            
            while(nptr1){
                while(nptr2){
                    if(nptr1->value == nptr2->value){
                        if(!L3.head){
                 
                            L3.head = new Node(nptr1->value);
                            nptr = L3.head;
                                              
                        }
                        else{
                            Node *p;
                            
                            p = new Node(nptr1->value);
                            while(nptr->next){
                                nptr=nptr->next;
                            }
                            nptr->next = p;
                            
                        }
                        //nptr2=L2.head;
                        break;
                    }
                    else{
                        nptr2= nptr2->next;
                    }
                }    //inner while
                nptr2=L2.head;
                nptr1=nptr1->next;
            }   //outer while
            cout<<"Intersection ";
            L3.display();

        }
        void Union(List &L1,List &L2){
            List L3;
            Node *nptr1 = L1.head;
            Node *nptr2 = L2.head;
            Node *nptr = L3.head;
             while (nptr1) {
                if (!L3.head) {
                    L3.head = new Node(nptr1->value);
                    nptr = L3.head;
                } else {
                    Node *p = new Node(nptr1->value);
                    while (nptr->next) {
                        nptr = nptr->next;
                    }
                    nptr->next = p;
                }
                nptr1 = nptr1->next;
            }

            nptr1 = L1.head; // Reset nptr1 to the head of L1
    while (nptr2) {
        while (nptr1) {
            if (nptr2->value == nptr1->value) {
                break; // Skip common elements
            }
            nptr1 = nptr1->next;
        }

        if (!nptr1) {
            // Element from L2 is not in L1, add it to L3
            Node *p = new Node(nptr2->value);
            while (nptr->next) {
                nptr = nptr->next;
            }
            nptr->next = p;
        }

        nptr1 = L1.head; // Reset nptr1 to the head of L1 for the next iteration
        nptr2 = nptr2->next;
    }

    cout << "Union ";
    L3.display();
}
        
    };


};

int main(){
    Node::List L,L1,L2;
    L1.Input();
    L1.display();
    L2.Input();
    L2.display();
    L.intersection(L1,L2);
    L.Union(L1,L2);
    // L.display();

}