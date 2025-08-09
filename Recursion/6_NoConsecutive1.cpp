#include <iostream>
#include <string>
using namespace std;

void BinString(int n,string ans, int lp){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    if(lp==0){
        BinString(n-1, ans+'0', 0);
        BinString(n-1, ans+'1', 1);
    }
    else{
        BinString(n-1, ans+'0', 0);
    }
}

//Without lastPlace(lp)

void BinString(int n,string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }
    int a=ans.length()-1;
    if(ans[a]!='1'){
        BinString(n-1, ans+'0');
        BinString(n-1, ans+'1');
    }
    else{
        BinString(n-1, ans+'0');
    }
}

int main(){
    int n=4;
    string ans="";
    BinString(n, ans,0);
    cout<<endl;
    cout<<"Without using lastPlace: "<<endl;
    BinString(n, ans);
    return 0;
}