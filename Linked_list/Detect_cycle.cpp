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

    bool isCycle(Node* head){
        Node* slow=head;
        Node* fast=head;
        while(fast!=nullptr && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(slow== fast){
                cout<<"Cycle Exist";
                return true;
            }
        }
        return false;
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
    

};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_front(0);
    ll.tail->next=ll.head;
    ll.isCycle(ll.head);
    


}