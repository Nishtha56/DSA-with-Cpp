#include <iostream>
using namespace std;

int tp(int n){   //2xn
    if(n==0 || n==1){
        return 1;
    }
    return tp(n-1) + tp(n-2);    // tp(n-1): for vertical , tp(n-2):= for horizonall rec calls
}  


int main(){
    int n=4;
    int a=tp(n);
    cout<<"Number of ways to put the tiles is : "<<a<<endl;
    return 0;
}