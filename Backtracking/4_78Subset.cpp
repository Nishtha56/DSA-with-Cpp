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
        AllSubset(nums, ans, i + 1, allSets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSets;
        vector<int> ans;
        AllSubset(nums, ans, 0, allSets);
        return allSets;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = s.subsets(nums);
    for (auto& subset : result) {
        for (int x : subset) cout << x << " ";
        cout << endl;
    }
}
