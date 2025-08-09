#include <iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll){
    list<int>::iterator itr;
    for(itr=ll.begin(); itr!=ll.end(); itr++){
        cout<<(*itr)<< " ";
    }
}

int main(){
    list<int> ll;

    //Push_front function
    ll.push_front(1);
    ll.push_front(2); //2->1
    ll.push_front(3); //3->2->1

    //Push back function
    ll.push_back(4);
    ll.push_back(5);
    ll.push_back(6);  //3->2->1->4->5->6
    
    //iterator: traverse
    printList(ll);

    //size function
    cout<<"\nTotal elements: "<<ll.size()<<endl;

    //head tail
    cout<<"Head:= "<<ll.front()<<endl;
    cout<<"Tail:= "<<ll.back();

    //pop front and pop back function

    ll.pop_front();
    cout<<"\n After deleting first : ";
    printList(ll);

    ll.pop_back();
    cout<<"\n After deleting last : ";
    printList(ll);
    return 0;

}