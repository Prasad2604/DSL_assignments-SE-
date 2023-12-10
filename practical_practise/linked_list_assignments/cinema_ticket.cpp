#include <iostream>
using namespace std;
#define rows 10
#define seats 7
class Node
{
    Node *next;
    Node *prev;
    char data;

public:
    Node()
    {
        next = NULL;
        prev = NULL;
        data = ' ';
    }
    Node(char data)
    {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
    class List
    {
        Node *head;
        Node *tail;

    public:
        List()
        {
            head = NULL;
            tail = NULL;
        }
        void ins_start()
        {
            Node *p = new Node(' ');
            if (!head)
            {
                head = p;
                p->next=head;
                p->prev=head;

            }
            else
            {
                // Node* nptr=head;
                p->next = head;
                p->prev = head->prev;
                head->prev->next = p;
                head->prev = p;
                head = p;
            }
        }
        void create_env(List st[])
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < seats; j++)
                {
                    st[i].ins_start();
                }
            }
        }
        void ins(char data,int pos){
            Node* p = new Node(data);
            if(pos==0 ){
                head=p;
                p->next=head;
                p->prev=head;
            }
            else{
                Node* nptr=head;
                pos--;
                while(pos and nptr->next!=head){
                    nptr=nptr->next;
                    pos--;
                }
                p->next = nptr->next;
                p->prev = nptr;
                nptr->next->prev = p;
                nptr->next = p;
            }
        }
        void insert(int pos){
            Node* nptr = head;
            while(--pos){
                nptr=nptr->next;
            }
            nptr->data='B';
        }

        void del(int pos){
            pos--;
            Node* nptr = head;
            while(pos--){
                nptr = nptr->next;
            }
            nptr->prev->next = nptr->next;
            nptr->next->prev = nptr->prev; 

        }
        void display()
        {
            Node *nptr = this->head;
            while (nptr->next != head)
            {
                cout << '(' << nptr->data << ')' << "->";
                nptr = nptr->next;
            }
            cout << '(' << nptr->data << ')';
            cout << endl;
        }
        void book_seat(List st[]){
            int n;
            cout<<"Enter number of seats you want to book :- ";
            cin>>n;
            if(n<=0){
                cout<<"Enter valid number of tickets "<<endl;
                cout<<"Have a good day!!"<<endl;
                return;
            }
            int r,s;
            while(n){
                cout<<endl;
                cout<<"--------------------------------------------------"<<endl;
                cout<<"Enter data for seat "<<n<<endl;
                cout<<"Enter row in which you want to book a seat :- ";
                cin>>r;
                cout<<"Enter seat number :- ";
                cin>>s;
                if(r<=10 and r>0 and s<=7 and s>0){
                    // st[r-1].del(s);
                    // st[r-1].ins('B',s-1);
                    // st[r-1].display();
                    st[r-1].insert(s);
                    st[r-1].display();
                    n--;   
                }
                else{
                    if(r<=0 || r>10){
                        cout<<"Enter valid row number"<<endl;
                    }
                    else if(s<=0 || s>10){
                        cout<<"Enter valid seat number"<<endl;
                    }
                }
            }
            
            

        }
        void cancel_seat(List st[]){
            int r, s;
            cout<<"Enter row in which you want to cancel your seat :- ";
            cin>>r;
            cout<<"Enter the seat you want to cancel :- ";
            cin>>s;
            if(r>0 and r<=10 and s>0 and s<=7){
                Node* nptr = st[r-1].head;
                while(--s){
                    nptr=nptr->next;
                }
                nptr->data=' ';
            }
            st[r-1].display();


        }
    };
};

int main()
{
    Node::List *st, l;
    st = new Node::List[rows];
    l.create_env(st);
    // for(int i=0;i<rows;i++){
    //     for(int j=0;j<seats;j++){
    //         st[i].display();
    //     }
    // }
    for (int i = 0; i < rows; i++)
    {

        cout << "ROW " << i + 1 << endl;
        st[i].display();
        cout << "------------------------------------" << endl;
    }
    l.book_seat(st);
    l.cancel_seat(st);
}