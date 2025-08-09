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
    
    return 0;


}