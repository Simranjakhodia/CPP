// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
       vector<vector<int>> res; 
        if(nums.empty()) return res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int target2 = target - nums[i] - nums[j];
                
                int front = j + 1;
                int back = n - 1;
                while(front < back){
                    int two_sum = nums[front] + nums[back];
                    if(two_sum < target2) front++;
                    else if(two_sum > target2) back--;
                    else {
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[back];
                        res.push_back(quadruplet);
                        
                        // Processing the duplicates of number 3
                        while(front < back && nums[front] == quadruplet[2]) ++front;
                        // Processing the duplicates of number 4
                        while(front < back && nums[back] == quadruplet[3]) --back;
                    }
                }
                while(j + 1 < n && nums[j ] == nums[j + 1]) ++j;
            }
            while(i + 1 < n && nums[i ] == nums[i + 1]) ++i;
        }
        
        return res;
    }
};


// https://www.youtube.com/watch?v=4ggF3tXIAp0
// https://leetcode.com/problems/4sum/discuss/8714/4Sum-C%2B%2B-solution-with-explanation-and-comparison-with-3Sum-problem.-Easy-to-understand.
