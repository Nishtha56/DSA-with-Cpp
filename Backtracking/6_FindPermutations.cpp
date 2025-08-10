#include<iostream>
using namespace std;

//TC => O(n!)    SC=O(n)

void f(string s, string ans){
    int n=s.size();
    if(n == 0){
        cout<<ans<<"\n";
        return;

    }
    for(int i=0;i<n;i++){
        char ch=s[i];
        //Eg: "abcdefg", i=2 => "ab" + "defg"  => s.substr(0, i) + s.substr(i+1, n-i-1);
        string nextStr=s.substr(0, i) + s.substr(i+1, n-i-1);
        f(nextStr, ans+ch); //ith character choice to add in permutation
    }
}
int main(){
    string s="abc";
    string ans="";
    f(s, ans);
}