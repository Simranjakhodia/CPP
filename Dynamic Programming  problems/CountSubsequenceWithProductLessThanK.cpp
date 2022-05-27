//  https://www.geeksforgeeks.org/count-subsequences-product-less-k/


#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int k) {
    int n = arr.size();
    vector<vector<int>>dp (n+1, vector<int>(k+1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j/arr[i-1]] + 1;
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}
int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << solve(A, k) << endl;
}
