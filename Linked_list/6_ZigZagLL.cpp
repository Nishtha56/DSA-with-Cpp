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

    void printList(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    Node* midAtSplit(Node* head){
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;

        while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL){
            prev->next=NULL;    //it split into two ll

        }
        return slow;      // it returns right head of a ll
    }

    Node* merge(Node* left, Node* right){
        Node* i=left;
        Node* j=right;
        List ans;

        while(i!=NULL && j!=NULL){
            if(i->data<=j->data){
                ans.push_back(i->data);
                i=i->next;
            }
            else{
                ans.push_back(j->data);
                j=j->next;
            }
        }
        while(i!=NULL){
            ans.push_back(i->data);
            i=i->next;
        }
        while(j!=NULL){
            ans.push_back(j->data);
            j=j->next;
        }
        return ans.head;   //simple oops vala concept

    }

    Node* mergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* rightHead=midAtSplit(head);    // Divides into mid
        Node* left= mergeSort(head);  //sort the left side
        Node* right=mergeSort(rightHead);    //sort thee right sideor right side LL
        return merge(left, right);
    }   
    
    Node* reverse(Node* head){
        Node* prev=NULL;
        Node*curr=head;
        Node*next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    Node* zigZag(Node* head){

        Node* rightHead=midAtSplit(head);  //it return second part of head
        Node* rightRev= reverse(rightHead);

        //Alternative merging 1st head=head; 2nd head=rightHead
        Node* left=head;
        Node* right=rightRev;
        Node* tail=right;

        while(left!=NULL && right!=NULL){
            Node*nextLeft=left->next;
            Node* nextRight=right->next;

            left->next=right;
            right->next=nextLeft;

            tail=right;

            left=nextLeft;
            right=nextRight;
        }
        if(right!=NULL){
            tail->next=right;
        }
        return head;

    }

};

int main(){
    List ll;

    ll.push_back(3);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(200);
    ll.push_back(100);

    cout<<"Unsorted List: ";
    ll.printList(ll.head);

    cout<<"Sorted after merge sort:= ";
    ll.head=ll.mergeSort(ll.head);
    ll.printList(ll.head);

    ll.head=ll.zigZag(ll.head);
    cout<<"ZigZag List: ";
    ll.printList(ll.head);
    return 0;


}