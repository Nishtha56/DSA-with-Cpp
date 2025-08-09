#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    
        Node(int val){
            data=val;
            next=nullptr;
        }
};

class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=NULL;;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }    
        else{
            newNode->next=head;
            head=newNode;
        }
    }
    void push_back(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;

        }
    }

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void insert(int val, int pos){
        Node* newNode=new Node(val);
        Node* temp=head;
        for(int i=0;i<pos-1;i++){
            if(temp->next==nullptr){
                cout<<"Invalid";
                return;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;

    }

    void pop_front(){
        if(head==NULL){
            cout<<"Linked list empty";
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next->next;
        temp->next=NULL;
        //tail=temp;

    }

    void iterative(int key){
        Node* temp=head;
        int c=0, flag=0;
        while(temp!=NULL){
            c++;
            if(temp->data==key){
                flag=1;
                break;
            }
            temp=temp->next;
            
        
        }
        if(flag==1){
            cout<<"Element is "<<c<<" in the position";
        }
        else{
            cout<<"-1";
        }
    }
    int helper(Node* temp,int key){
        if(temp==NULL){
            return -1;
        }
        if(temp->data==key){
            return 0;
        }
        int idx=helper(temp->next, key);
        if(idx==-1){
            return -1;
        }
        return idx+1;

    }
    int RecSearch(int key){
        helper(head, key);
    }

    void reverse(){
        Node * prev=NULL;
        Node* curr=head;
        

        while(curr!=NULL){

            Node* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

    
    void removeNth(int n){
        Node* prev=head;

        int size=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            size++;
        }
        for(int i=0;i<size-n;i++){
            prev=prev->next;
        }
        Node* toDel=prev->next;
        prev->next=prev->next->next;
    }

};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.printList();

    ll.push_back(4);
    ll.push_back(5);
    ll.printList();

    ll.insert(100,4);
    ll.printList();

    ll.pop_front();
    ll.printList();

    ll.pop_back();
    ll.printList();

    ll.iterative(4);
    cout<<endl;
    cout<<ll.RecSearch(4);

    cout<<"\n Reverse list: ";
    ll.reverse();
    ll.printList();

    ll.removeNth(100);
     cout<<"\n Remving element from the list: ";
    ll.printList();


    


}