// https://leetcode.com/problems/range-sum-query-2d-immutable/submissions/


class NumMatrix {
public:
    vector<vector<int>> prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); // no of rows
        int n = matrix[0].size(); // no of cols
        prefix = vector<vector<int>>(m+1, vector<int> (n+1, 0));
     // Pre-processing of nums array to prefix array
     /*    for(int j = 0 ; j <= n; j++)
               prefix[0][j] = 0;
           for(int i = 0; i <= m; i++)
               prefix[i][0] = 0;   */
        for(int i = 1; i <= m; i++) {
           for(int j = 1; j <= n; j++) {
               prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
       }
       // Pre-processing done Time : O(mn)
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       
       
        int res = prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1];  // O(1)
        return res;
       
    }
};

// https://www.youtube.com/watch?v=tk0Twx2VQy8

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
