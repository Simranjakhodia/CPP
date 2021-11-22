// https://leetcode.com/problems/unique-paths/submissions/

class Solution {
public:
    /*
    int uniquePaths(int m, int n) {
       
        return uniquePaths1(m , n , 0 , 0);
    }

        int uniquePaths1(int m, int n, int i, int j){
        if(i == m-1 && j == n-1)
            return 1;
        else if(i == m-1)
            return uniquePaths1(m, n , i, j+1 );
        else if(j == n-1)
            return uniquePaths1(m, n , i+1, j);
        return uniquePaths1(m, n , i, j+1 ) + uniquePaths1(m, n , i+1, j);
    }
    
    */ // MT-1 Gives TLE
     int uniquePaths(int m, int n) {
        int dp[m][n];
        for(int i = 0; i < m; i++){
           dp[i][0] = 1; 
        }
        for(int j = 0; j < n; j++){
            dp[0][j] = 1;
        } 
        for(int i = 1; i < m ; i++){
            for(int j = 1; j < n ; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1]; 
    }
};
