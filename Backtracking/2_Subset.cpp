#include<iostream>
using namespace std;

void Subset(string s, string ans){
    if(s.size() == 0){
        cout<<ans<<"\n";
        return;
    }
   
    char ch=s[0];
    Subset(s.substr(1,(s.size()-1)), ans+ch);   //yes choice
    Subset(s.substr(1,(s.size()-1)), ans);      //no choice
}

int main(){
    string s="abc";
    string ans="";
    Subset(s,ans);
    return 0;
}