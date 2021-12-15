// https://leetcode.com/problems/3sum/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for(auto i = 0; i < nums.size(); ){
            int target = -nums[i];
            int l = i + 1, u = nums.size() - 1;
            
            while(l < u){
                auto sum = nums[l] + nums[u];
                
                if(sum < target){
                    while (++l < nums.size() && nums[l] == nums[l-1]); // processing duplicates of number 2;
               }
                else if(sum > target){
                    while(--u < nums.size() && nums[u] == nums[u+1]); // processing duplicates of number 3;
                }
                else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[u]});
                    while(++l < nums.size() && nums[l] == nums[l-1]);
                    while(--u < nums.size() && nums[u] == nums[u+1]);
                }
                
            }
            while(++i < nums.size() && nums[i] == nums[i-1]);
        }
        return res;
    }
};
