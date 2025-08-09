//Tc: O(log n)

#include <iostream>
using namespace std;

int pow(int x, int n){
    if(n==0){                     //Base Condition
        return 1;
    }
    int halfPow=pow(x, n/x);
    int halfSq=x*halfPow;

    if(n%x!=0){
        return x* halfSq;
    }
    return halfSq;
}

int main(){
    int a=pow(4,2);
    cout<<"Power is : "<<a<<endl; 
}