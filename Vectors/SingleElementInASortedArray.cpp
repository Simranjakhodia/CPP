// https://leetcode.com/problems/single-element-in-a-sorted-array/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = l + (r - l)/ 1;
            bool isHalfEven = (mid - l) % 2 == 0;
            
            if(mid + 1 < nums.size() && nums[mid] == nums[mid + 1])
                if(isHalfEven)
                    l = mid + 2;
                else r = mid - 1;
            else if(mid && nums[mid] == nums[mid - 1])
                if(isHalfEven)
                    r = mid - 2;
                else l = mid + 1;
            else
                return nums[mid];
            
        }
        return -1;
     
    }
};




//  https://leetcode.com/problems/single-element-in-a-sorted-array/discuss/1587270/C%2B%2B-5-Simple-Solutions-w-Explanation-or-Hashmap-%2B-XOR-%2B-Linear-Search-%2B-Binary-Search
