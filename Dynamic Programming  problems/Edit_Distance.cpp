// https://leetcode.com/problems/edit-distance/


class Solution {
public:
    
     /* MT-2 : DP : Memoization
       int dp[1000][1000]; 
       int funct1(string& word1, string& word2, int m, int n){
           if( m == 0)
               return n;
           if( n == 0)
               return m;
           if(dp[m][n] != -1)
               return dp[m][n];
           if(word1[m-1] == word2[n-1]){
               dp[m][n] = funct1(word1, word2, m-1, n-1);
               return dp[m][n];
           }
           dp[m][n] = 1 + min( {funct1(word1, word2, m, n-1) , funct1(word1, word2, m-1, n), funct1(word1, word2, m-1, n-1)});
              return dp[m][n];
       }
       int minDistance(string word1, string word2){
           int m = word1.length();
           int n = word2.length();
           
           for(int i = 0; i <= m+1; i++)
               for(int j = 0; j <= n+1; j++)
                   dp[i][j] = -1;
           return funct1(word1, word2, m, n);
       }
       
       */ 
    
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        int dp[m+1][n+1];
        if(m == 0)
            return n;
        if(n == 0)
            return m;
        for(int i = 0; i < m+1; i++)
            dp[i][0] = i;
        for(int j = 0; j < n+1; j++)
            dp[0][j] = j;
        for(int i = 1; i < m+1; i++){
            for(int j = 1; j < n+1; j++){
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = 1+ min({dp[i-1][j]         // delete
                                        , dp[i][j-1],     // insert
                                       dp[i-1][j-1]});    // substitute/ replace
            }
        }
        return dp[m][n];   // Time complexity is : O(m*n) : DP : Tabulation
    } 
    
};    


// https://www.youtube.com/watch?v=AuYujVj646Q
// https://leetcode.com/problems/edit-distance/discuss/662240/C%2B%2B-Easy-DP-Solution-(Well-Commented-)
// https://leetcode.com/problems/edit-distance/discuss/501094/c%2B%2B-recursive-memoization-and-tabulation-Method
