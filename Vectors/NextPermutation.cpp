// https://leetcode.com/problems/next-permutation/submissions/


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return;
        int i, idx = 0, pos = 0;
        for(i = nums.size()-1; i > 0; i--){
            if(nums[i-1] > nums[i]) continue;
            if(nums[i-1] < nums[i]) {
                idx = i-1; break;
            }
        }
        if(i == 0) reverse(nums.begin(), nums.end());
        else {
            for(int i = nums.size()-1; i > idx ; i--){
                if(nums[i] > nums[idx])  {
                    pos = i;
                    break;
                }
            }
            swap(nums[pos], nums[idx]);
            reverse(nums.begin() + idx + 1, nums.end());
        }   
    }
};


// https://www.youtube.com/watch?v=LuLCLgMElus
