#include <iostream>
using namespace std;

//Factorial 
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}

//Sum of natural number
int sum(int n){
    if(n==1){
        return 1;
    }
    return n+sum(n-1);
}

//Fibonacci Number
int fib(int n){
    if(n==1){
        return 1;
    }
    if(n==0){
        return 0;
    }
    return fib(n-2)+fib(n-1);
}

//print n to 1
void print(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    print(n-1);
}

//Ascending order
void asc(int n){
    if(n==0){
        return;
    }
    asc(n-1);
    cout<<n<<" ";
}

// is array is a sorted or not
bool isSorted(int arr[], int n, int i){
    if(i==n-1){
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr, n, i+1);
}

int main(){
    int a=fact(5);
    cout<<"Factorial is: "<<a<<endl;

    int b=sum(5);
    cout<<"Sum of natural number is : "<<b<<endl;

    int c=fib(6);
    cout<<"Fibonacci number: "<<c<<endl;

    cout<<"Print n to 1: ";
    print(5);
    cout<<endl;
    cout<<"Print 1 to n: ";
    asc(5);
    cout<<endl;

    int arr1[5]={1,2,3,4,5};
    
    cout<<"Array is sorted or not: "<<isSorted(arr1, 5,0);
    return 0;
}