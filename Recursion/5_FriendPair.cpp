#include <iostream>
using namespace std;

int friendPair(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    return friendPair(n-1) + (n-1)*friendPair(n-2);
}

int main(){
    int n=3;
    int a=friendPair(n);
    cout<<a<<endl;
    return 0;
}