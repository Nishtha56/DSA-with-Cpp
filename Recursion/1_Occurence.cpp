#include<iostream>
#include <vector>
using namespace std;

//First Occurence
int FO(vector<int> arr,int i, int target){
    if(i==arr.size()){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return FO(arr, i+1, target);
}

//Last Occurence
int LO(vector<int> arr, int i, int target){
    
    if(i==0){
        return -1;
    }
    if(arr[i]==target){
        return i;
    }
    return LO(arr, i-1, target);
}

int main(){
    vector<int> arr={1,2,3,4,5,5,3,8};
    int target=3;
    int a= FO(arr, 0, target);
    cout<<"First Ocuurence of a element in a vector is: "<<a<<endl;

    int n=arr.size();
    int b= LO(arr, n, target);
    cout<<"Last Ocuurence of a element in a vector is: "<<b<<endl;
}