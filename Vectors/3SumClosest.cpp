// https://leetcode.com/problems/3sum-closest/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        for(auto i = 0; i < nums.size(); ++i){
           // int target = -nums[i];
            int l = i + 1, u = nums.size() - 1;
            
            while(l < u){
                int curr_sum = nums[i] + nums[l] + nums[u];
                if(curr_sum == target) return curr_sum;
                if(abs(target - curr_sum) < abs(target - closest))
                    closest = curr_sum;
                if(curr_sum > target)
                    --u;
                else ++l;
            }
        }
        return closest;
    }
};
