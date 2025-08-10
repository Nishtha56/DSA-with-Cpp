#include <iostream>
using namespace std;

void DecBin(int num){
    int n=num;
    int pow=1;  //10^0=1
    int bin=0;

    while(n>0){
        int rem=n%2;
            bin+=rem*pow;
            pow*=10;
            n=n/2;
    }
    cout<<bin;

}

int main(){
    DecBin(7);
    return 0;
}