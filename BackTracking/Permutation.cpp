// https://leetcode.com/problems/permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        vector<vector<int>> res;
        vector<int> permutation;
        permute(nums, res, permutation, used);
        return res;
    }
private:
    void permute(vector<int> &nums, vector<vector<int>>&res, vector<int>&permutation, vector<bool>&used) {
        if(permutation.size() == nums.size()){
            res.push_back(permutation);
            return;
        }
        
        for(int i = 0 ; i  < nums.size(); i++) {
            if(used[i] == true) continue;   // if a no is already included in set, then move to next no.
            used[i] = true;
            permutation.push_back(nums[i]);
            
            permute(nums, res, permutation, used);
            
            used[i] = false;   // backtracking
            permutation.pop_back();
        }
    }
};
