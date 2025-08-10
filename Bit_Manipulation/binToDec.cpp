#include <iostream>
using namespace std;
void binDec(int num){
    int n=num;
    int dec=0;
    int pow=1;  // 2^0=1

    while(n>0){
        int last=n%10;
        dec+=pow*last;
        pow*=2;
        n/=10;
    }
    cout<<dec;
}
int main(){
    binDec(101);
    return 0;
}