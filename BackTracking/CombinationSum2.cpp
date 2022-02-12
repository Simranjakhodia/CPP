// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combinations;
        vector<vector<int>> res;
        combinationSum2(candidates, target, combinations, res, 0);
        return res;
    }
    
private:
    void combinationSum2(vector<int>& candidates, int target, vector<int>&combinations,vector<vector<int>> &res, int begin) {
        if(!target) {
            res.push_back(combinations);
            return;
        }
        for(int i = begin; i != candidates.size() && target >= candidates[i]; i++) {
            
            if(i == begin || candidates[i] != candidates[i-1]) {
                combinations.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], combinations, res, i+1);
                combinations.pop_back();
            }    
        }
    }
};
