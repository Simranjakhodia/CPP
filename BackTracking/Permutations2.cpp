// https://leetcode.com/problems/permutations-ii/submissions/


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> permutation;
        vector<vector<int>> res;
        unordered_map<int, int> m;
        for(int i : nums) {
            m[i]++;
        }
        sort(nums.begin(), nums.end());
        permuteUnique(nums, res, permutation, m);
        
        return res;
    }
private:
    void permuteUnique(vector<int>& nums, vector<vector<int>>& res, vector<int>& permutation, unordered_map<int, int> &m){
        if(permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }
        for(auto &p : m) {
            if(p.second <= 0) continue;
            p.second--;
            permutation.push_back(p.first);
            permuteUnique(nums, res, permutation, m);
            permutation.pop_back();
            p.second++;
        }
    }
};                                                                                                                                                  
