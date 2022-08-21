//  https://www.geeksforgeeks.org/minimum-cost-to-fill-given-weight-in-a-bag/?ref=lbp


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int helper(vector<int> cost, int n, int w) {
    if(n <= 0 && w == 0) return 0;
    if(n <= 0) return 1e9+7;
    if(w == 0) return 0;
    if(dp[n][w] != -1) return dp[n][w];
    if(n > w || cost[n-1] == -1) 
        return dp[n][w] = helper(cost, n-1, w);
    
    return dp[n][w] = min(helper(cost, n-1, w), cost[n-1] + helper(cost, n, w - n));
    
}
int minCost(vector<int> cost, int w) {
    int n = cost.size();
    int res = helper(cost, n, w);
    return res == 1e9+7 ? -1 : res ;
}

int main() {
    vector<int> cost = {20, 10, 4, 50, 100};
    
    int w = 5;
    dp.resize(cost.size()+1, vector<int>(w+1, -1));
    cout << minCost(cost, w) << endl;
    return 0;
}
