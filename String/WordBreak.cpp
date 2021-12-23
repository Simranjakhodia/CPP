// https://leetcode.com/problems/word-break/submissions/

class Solution {
public:
    
    /* MT-1 Brute Force Gives TLE
    bool wordBreak(string s, vector<string>& wordDict) {
        set <string> set (wordDict.begin(), wordDict.end());
        return dp(s, set);
    }
    bool dp(string s, set <string> set){
        int len = s.length();
        if (len == 0)   return true;
        for (int i = 1; i <= len; i++) {
            if ( set.find(s.substr(0, i)) != set.end() && dp(s.substr(i), set))
                return true;
        }
        return false;
    }
    
    */
    // MT2 Runtime: 4ms
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set <string> set (wordDict.begin(), wordDict.end());
        int len = s.length();
        vector<bool> dp (len+1, false);
        dp[0] = true;
        for(int i = 1 ; i <= len; i++){
            for(int j = i-1; j >= 0; j--){
                if(dp[j] && set.find(s.substr(j, i-j)) != set.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};


// https://leetcode.com/problems/word-break/discuss/169383/solved-The-Time-Complexity-of-The-Brute-Force-Method-Should-Be-O(2n)-and-Prove-It-Below
// https://leetcode.com/problems/word-break/discuss/43814/
