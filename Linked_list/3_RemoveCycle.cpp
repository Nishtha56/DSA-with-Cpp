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
    public:
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

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void removeCycle(Node* head){
       
        Node* slow=head;
        Node* fast=head;
        bool cycle=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow== fast){
                cycle=true;
                break;
            }
        }
        if(!cycle){
            cout<<"Cycle does not exist";      
        }
        else{
            //Special case : when slow and fast both in head
            if(fast==slow){
                while(fast->next!=slow){
                    fast=fast->next;
                }
                fast->next=NULL;
            }
            else{
                slow=head;
                Node* prev=fast;
                while(slow!=fast){
                    slow=slow->next;
                    prev=fast;
                    fast=fast->next;
                }
                prev->next=NULL;
            }
        }
        
    
    }

    

};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.tail->next=ll.head;
    ll.removeCycle(ll.head);

    ll.printList();
    


}