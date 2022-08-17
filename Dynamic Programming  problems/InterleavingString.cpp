///   https://leetcode.com/problems/interleaving-string/


class Solution {
public:
    int dp[1001][1001];
    bool solve(string a, string b, string c, int n, int m, int len) {
        if(len == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        
        int p, q;
        p = q = 0;
        if(n-1 >= 0 && a[n-1] == c[len-1]) 
            p = solve(a, b, c, n-1, m, len-1);
        if(m-1 >= 0 && b[m-1] == c[len-1])
            q = solve(a, b, c, n, m-1, len-1);
        
        return dp[n][m] = p || q;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        int len = s3.length();
        if(n+m != len) return 0;
        dp[n][m];
        memset(dp, -1, sizeof dp);
        return solve(s1, s2, s3, n, m, len);
    }
};


// tc O(N^2) sc o(n^2) 
