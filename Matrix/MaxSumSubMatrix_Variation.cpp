// https://practice.geeksforgeeks.org/problems/max-sum-submatrix2725/1



class Solution{
public:
    vector<int> maxSubMatrixSumQueries(vector<int> mat[], int n, int m,
                                   vector<pair<int, int>> &queries, int q) {
        vector<int> ans;
        int preSum[n+1][m+1];
        for(int i = 0; i <= n; i++)
            preSum[i][0] = 0;
            
        for(int i = 0; i <= m; i++) 
            preSum[0][i] = 0;
            
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                preSum[i][j] = mat[i-1][j-1] + preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1];
            }
        }
        
        for(pair<int, int> pre : queries) {
            int maxr = 0, temp, k = pre.first, l = pre.second;
            
            for(int i = k; i <= n; i++) {
                for(int j = l; j <= m; j++) {
                    temp = preSum[i][j] - preSum[i][j-l] - preSum[i-k][j] + preSum[i-k][j-l];
                    if(temp > maxr)
                        maxr = temp;
                }
            }
            ans.push_back(maxr);
        }
        return ans;
    }
};



Expected Time Complexity: O(Q*N*M)
Expected Auxiliary Space: O(N*M)
