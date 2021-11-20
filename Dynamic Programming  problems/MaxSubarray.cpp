
// https://leetcode.com/problems/maximum-subarray


class Solution {
public:
    // MT!
    /*int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int sum = 0, max_sum = INT_MIN;
        for(int i = 0; i < n; i++){
           
                sum += nums[i];
                max_sum = max(max_sum, sum); 
                max_sum = max(max_sum, nums[i]);
         
            if(sum < nums[i]) sum = max(0,nums[i]);
        }
        return max_sum;    
    }
    */
    
    // mt-2 https://leetcode.com/problems/maximum-subarray/discuss/20193/DP-solution-and-some-thoughts
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev = nums[0], curr = 0;
        int max_sum = nums[0];
        for(int i = 1; i < n; i++){
            curr = nums[i] + ((prev > 0)? prev : 0);
            max_sum = max(max_sum , curr);
            prev = curr;
        }
        return max_sum;
    }
    
};
