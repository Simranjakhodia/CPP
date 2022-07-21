//  https://leetcode.com/problems/solving-questions-with-brainpower/



class Solution {
public:
    long long dfs(vector<vector<int>>& q, vector<long long>& dp, int idx, int n) {
        if(idx >= n) return 0;
        if(dp[idx] > 0) return dp[idx];
        
        long long pick = dfs(q, dp, idx+q[idx][1]+1, n) + q[idx][0];
        long long notpick = dfs(q, dp, idx+1, n);
        
        return dp[idx] = max(pick, notpick);
    }
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, 0);
        return dfs(q, dp, 0, n);
    }
};

class Solution1 {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();
        vector<long long> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--) {
            int points = q[i][0], jmp = q[i][1];
            dp[i] = max(points + dp[min(i+jmp+1, n)], dp[i+1]);
        }
        return dp[0];
    }
};


// https://leetcode.com/problems/solving-questions-with-brainpower/discuss/1692920/Python3-Java-C%2B%2B-Dfs-%2B-Memoization-Iterative-O(n)
