#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void AllSubset(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSets) {
        if (i == nums.size()) {
            allSets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        AllSubset(nums, ans, i + 1, allSets);
        ans.pop_back();

        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        AllSubset(nums, ans, idx, allSets);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSets;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        AllSubset(nums, ans, 0, allSets);
        return allSets;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = s.subsets(nums);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << "[";
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j];
            if (j + 1 < result[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < result.size()) cout << ",";
    }
    cout << "]" << endl;
}

