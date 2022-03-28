// https://leetcode.com/problems/maximum-length-of-repeated-subarray


class Solution {
public:
    // Brute Force TLE   TC: O(M * N * min(M, N))
    int findLength1(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                int k = 0;
                while(nums1[i + k] == nums2[j + k]) k++;
                ans = max(ans, k);
            }
        }
        return ans;
    }
    
    // MT 2 : DP TC : O( M * N) ; SC : O(M * N)
    
    int findLength2(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        for(int i = 1 ;i <= nums1.size(); i++) {
            for(int j = 1; j <= nums2.size(); j++) {
                if(nums1[i-1] == nums2[j-1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                
                ans = max(ans, dp[i][j]); 
            }
        }
        return ans;
    }
    
    // MT 3 : Optimised DP TC : O( M * N) ; SC : O(N)
    
     int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m < n) return findLength(nums2, nums1); 
        vector<int> dp(n+1), prevDP(n+1);
        int ans = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (nums1[i-1] == nums2[j-1])
                    dp[j] = prevDP[j-1] + 1;
                else dp[j] = 0;
                ans = max(ans, dp[j]);
            }
            dp.swap(prevDP);
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/discuss/1324248/C%2B%2BPython-DP-KMP-Hashing-Solutions-Clean-and-Concise-O(NlogN)
