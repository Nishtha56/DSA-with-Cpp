#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class DoublyLL{
    public:
    Node* head;
    Node* tail;

    DoublyLL(){
        head=NULL;
        tail=NULL;
    }

    void push_front(int val){
        Node* newNode=new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void printList(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"<=>";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void push_back(int val){
        Node* newNode= new Node(val);

        if(head==NULL){
            head=tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }

    void pop_front(){
        Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node* temp=head;
        if(head!=NULL){
            head->prev=NULL;
        }
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        

    }

};
int main(){
    DoublyLL dll;

    dll.push_front(4);
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    cout<<"Doubly LL is: ";
    dll.printList();   //1<=>2<=>3<=>4<=>NULL

    dll.pop_front();
    cout<<"After deleting first elemet: ";
    dll.printList();

    dll.push_back(10);
    dll.push_back(20);
    dll.push_back(30);
    dll.push_back(40);
    dll.push_back(50);
    cout<<"Adding elements from back in Doubly ll: ";
    dll.printList();

    dll.pop_back();
    dll.printList();

    return 0;
}