// https://leetcode.com/problems/longest-increasing-path-in-a-matrix

class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& m, int r, int c) {
        if(dp[r][c] > 0) return dp[r][c];
        int res = 1;
        if(r+1 < rows && m[r+1][c] > m[r][c]) res = max(res, 1 + dfs(m, r+1, c));
        if(r-1 >= 0 && m[r-1][c] > m[r][c]) res = max(res, 1 + dfs(m, r-1, c));
        if(c+1 < cols && m[r][c+1] > m[r][c]) res = max(res, 1 + dfs(m, r, c+1));
        if(c-1 >= 0 && m[r][c-1] > m[r][c]) res = max(res, 1 + dfs(m, r, c-1));
        dp[r][c] = res;
        return dp[r][c];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
         rows = matrix.size();
        if(!rows) return 0;
        cols = matrix[0].size();
        dp = vector<vector<int>>(rows, vector<int> (cols, 0));
        int res = 0;
        for(int i = 0; i < rows; i++) 
            for(int j = 0; j < cols; j++)
                res = max(res, dfs(matrix, i, j));
        
        return res;
    }
};

// https://www.youtube.com/watch?v=uLjO2LUlLN4
