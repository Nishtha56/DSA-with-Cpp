#include<bits/stdc++.h>
using namespace std;

void PSubset(vector<int> &arr, vector<int> &ans, int i){
    if(i==arr.size()){
        for(int val : ans){
            cout<<val<<" ";
            
        }
        cout<<endl;
        return;
    }
    ans.push_back(arr[i]);     //Include
    PSubset(arr, ans, i+1);

    ans.pop_back();  // Delete last element in the ans
    PSubset(arr, ans, i+1);

}

int main(){
    vector<int> arr={1,2,3};
    vector<int> ans;
    PSubset(arr,ans,0);

    
    return 0;
}