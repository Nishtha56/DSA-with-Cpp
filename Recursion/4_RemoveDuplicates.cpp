#include <iostream>
#include<string>
using namespace std;
void remDup(string str, string ans, int i, bool map[26]){
    char ch=str[i];
    int mapIdx=(int)(ch - 'a');   // type caste: a->0, b->1..., z->26 

    if(i==str.length()){
        cout<<ans<<endl;
        return;
    }
    if(map[mapIdx]){
        remDup(str, ans, i+1, map);
    }
    else{
        map[mapIdx]=true;
        remDup(str, ans+str[i],i+1, map);
    }

}

void remDup1(string str, string ans, bool map[26]){
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    int n=str.length();
    char ch=str[n-1];
    int mapIdx=(int)(str[n-1] - 'a');  //typecaste
    str=str.substr(0,n-1);

    if(map[mapIdx]){
        remDup1(str, ans, map);
    }
    else{
        map[mapIdx]=true;
        remDup1(str, ch+ans, map);
    }

}

int main(){
    string str="appnnaacoollegeye";
    string ans="";

    bool map[26]={false};
    bool map1[26]={false};
    remDup(str, ans, 0, map);
    remDup1(str,ans, map1);
}