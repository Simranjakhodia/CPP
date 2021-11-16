// https://leetcode.com/problems/missing-number/

class Solution {
public:
    int missingNumber1(vector<int>& nums) {
        int i;
        for( i = 0; i < nums.size(); i++){
            if(find(nums.begin(), nums.end(), i) != nums.end())
                continue;
             return i;
        }
        return i;
    }
    int missingNumber2(vector<int>& nums) {  //(best)faster than 56.99% Memory Usage: 17.9 MB, less than 93.18% 
        int i, res = 0;
        for(i = 0; i < nums.size() ; i++){
         res = res ^ i ^ nums[i];
        }
        return res ^ i;
    }
    int missingNumber(vector<int>& nums) {
        int s = nums.size() * (nums.size() + 1 ) / 2 ;
        int k = 0;
        for(int i = 0; i < nums.size() ; i++)
            k += nums[i];
        return s - k;
    }    
};
