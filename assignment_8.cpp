#include<iostream>
using namespace std;

class Node{
    Node* next;
    Node* prev;
    int value;
    public:
    Node(){
        next = NULL;
        prev = NULL;
        value = 0;
    }
    Node(int value){
        next = NULL;
        prev = NULL;
        this->value = value;
    }
    class DoubleLinkedList{
        Node* head;
        public:
        DoubleLinkedList(){
            head= NULL;
        }
        void ins_start(int x){
            
            Node* temp = new Node(x);
            if(!head){
                // head = new Node(x);
                // head->next=head;
                // head->prev=head;
                head=temp;
                head->next = temp;
                head->prev = temp;
            }
            else{
                
                temp->next = head;
                temp->prev = head->prev;
                head->prev->next = temp;
                head->prev = temp;
                head = temp;
            }

        }

         void append(int x) {
            Node* temp = new Node(x);
            if (!head) {
                head = temp;
                head->next = temp;
                head->prev = temp;
            } else {
                temp->next = head;
                temp->prev = head->prev;
                head->prev->next = temp;
                head->prev = temp;
            }
        }


        void display(){
            Node* nptr;
            nptr  = head;
            cout<<"Binary :- ";
            while(nptr->next!=head){
                cout<<nptr->value<<" ";
                nptr = nptr->next;
            }
            if(nptr->next==head){
                cout<<nptr->value<<" ";
            }
            cout<<endl;
        }
        void convert_binary(){
            int p;
            cout<<"Enter number you want to convert to binary :- ";
            cin>>p;
            while(p>0){
                // cout<<"Hello"<<endl;
                this->ins_start(p%2);
                p = p/2;
            }
            this->display();
        }
        void one_compl(){
            Node* nptr;
            nptr  = head;
            cout<<"1's complement :- ";
            // while(nptr->next!=head){
            //     if(nptr->value==0){
            //         cout<<1<<" ";
            //         nptr = nptr->next;
            //     }
            //     else{
            //         cout<<0<<" ";
            //         nptr = nptr->next;
            //     }
                
            // }
            // if(nptr->next==head){
            //     if(nptr->value){
            //         cout<<0<<" ";
            //     }
            //     else{
            //         cout<<1<<" ";
            //     }
                
            // }
            do {
                cout << !nptr->value << " ";
                nptr = nptr->next;
            } while (nptr != head);
            cout<<endl;
        }

        void two_comp() {
            Node* nptr = head;
            DoubleLinkedList d;
            int carry = 1;
            cout << "Two's Complement: ";
            do {
                d.append(nptr->value ^ carry);
                carry = carry & nptr->value;
                nptr = nptr->next;
            } while (nptr != head);

            if (carry) {
                d.append(carry);
            }

            d.display();
        }

        void bin_sum(DoubleLinkedList &d2){
            Node* nptr1 = head;
            Node* nptr2 = d2.head;
            DoubleLinkedList result;
            int carry = 0;

            do {
                int sum = nptr1->value + nptr2->value + carry;
                result.append(sum % 2);
                carry = sum / 2;

                nptr1 = nptr1->next;
                nptr2 = nptr2->next;
            } while (nptr1 != head && nptr2 != d2.head);

            // If one list is longer than the other
            while (nptr1 != head) {
                int sum = nptr1->value + carry;
                result.append(sum % 2);
                carry = sum / 2;
                nptr1 = nptr1->next;
            }

            while (nptr2 != d2.head) {
                int sum = nptr2->value + carry;
                result.append(sum % 2);
                carry = sum / 2;
                nptr2 = nptr2->next;
            }

            // If there is a carry after the loop
            if (carry) {
                result.append(carry);
            }

            result.display();

        }
    };
};

int main(){
    Node::DoubleLinkedList d1,d2;
    d1.convert_binary();
    d1.one_compl();
    d1.two_comp();
    d2.convert_binary();
    d2.one_compl();
    d2.two_comp();
    d1.bin_sum(d2);
    return 0;

}