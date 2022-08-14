//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/discuss/2424289/C%2B%2B-or-Intuition-or-3D-Memoization-greater-3D-Tabulation-greater-2D-Space-optimization



int f(vector<int>& p, int idx, bool buy, int k) {
    int n = p.size();
    if(k == 0 || idx == n) return 0;
    
    int ans = 0;
    if(buy) {
        int b = -p[idx] + f(p, idx + 1, 0, k);
        int nb = 0 + f(p, idx + 1, 1, k);
        ans = max(b, nb);
    }
    else {
        int s = p[idx] + f(p, idx + 1, 1, k - 1);
        int ns = 0 +  f(p, idx + 1, 0, k);
        ans = max(s, ns);
    }
    return ans;
}

int maxProfit(int k, vector<int>& p) {
    int n = p.size();
    return f(p, 0, 1, k);
}

TC : O(2 ^ N)
SC : O(2*k*N)


//////////////////////////////////////////////////


int f(vector<int>& dp, int idx, bool buy, int k, vector<vector<vector<int>>> &dp) {
    int n = p.size();
    if(k == 0 ||idx == n) return 0;
    if(dp[idx][buy][k] != -1) return dp[idx][buy][k];
    
    int ans = 0;
    if(buy) {
        int b = -p[idx] + f(p, idx + 1, 0, k, dp);
        int nb = 0 + f(p, idx+1, 1, k, dp);
        ans = max(b, nb);
    }
    else {
        int s = p[idx] + f(p, idx + 1, 1, k-1, dp);
        int bs = f(p, idx + 1, 0, k, dp);
        ans = max(s, bs);
    }
    return dp[idx][buy][k] = ans;
}

int maxProfit(int k, vector<int>& p) {
    int n = p.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return f(p, 0, 1, k, dp);
}

TC : O(N)
SC : O(2*K*N) + O(N)

/////////////////////////////////////////


class Solution {
public:
    int solve(vector<int>&prices, int idx, int left, vector<vector<int>>& dp) {
        if(left== 0) return 0;
        if(idx == prices.size()) return 0;
        if(dp[idx][left] != -1) return dp[idx][left];
        
        int ans1 = solve(prices, idx+1, left, dp);
        int ans2 = 0;
        
        bool buy = (left % 2 == 0);
        if(buy == true)
            ans2 = -prices[idx] + solve(prices, idx+1, left-1, dp);
        else 
            ans2 = prices[idx] + solve(prices, idx+1, left-1, dp);
        
        return dp[idx][left] = max(ans1, ans2);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(5, -1));
        int ans = solve(prices, 0, 4, dp);
        return ans;
    }
};

