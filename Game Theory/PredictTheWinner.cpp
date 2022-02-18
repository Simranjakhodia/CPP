//


class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      //  int scoreFirst = PredictTheWinnerFrom2(nums, 0, nums.size() - 1);
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), -1));
        int scoreFirst = PredictTheWinnerFrom(nums, 0, nums.size() - 1, memo);   // Top-down memo
        int scoreTot = getTotalScore(nums);
        
        return scoreFirst >= scoreTot - scoreFirst; 
    }
private :
    int PredictTheWinnerFrom2(vector<int>& nums, int i, int j) {
        if(i > j) return 0;
        if(i == j) return nums[i];
        
        int curScore = max(nums[i] + min(PredictTheWinnerFrom2(nums, i + 2, j), PredictTheWinnerFrom2(nums, i + 1, j - 1)), 
                          nums[j] + min(PredictTheWinnerFrom2(nums, i + 1, j - 1), 
PredictTheWinnerFrom2(nums, i, j - 2)));
        
        return curScore;   
    }
    
    int PredictTheWinnerFrom(vector<int>& nums, int i, int j, vector<vector<int>>& memo) {
        if(i > j) return 0;
        if(i == j) return nums[i];
        if(memo[i][j] != -1) return memo[i][j];
        
        int curScore = max(nums[i] + min(PredictTheWinnerFrom(nums, i + 2, j, memo), PredictTheWinnerFrom(nums, i + 1, j - 1, memo)),
                          nums[j] + min(PredictTheWinnerFrom(nums, i + 1, j - 1, memo), PredictTheWinnerFrom(nums, i, j - 2, memo)));
        
        memo[i][j] = curScore;
        return memo[i][j];
    }
    int getTotalScore(vector<int> nums) {
        int sum = 0 ;
        for(auto &num : nums)
            sum += num;
        return sum;
    }
    
 
};

// https://leetcode.com/problems/predict-the-winner/discuss/155217/From-Brute-Force-to-Top-down-DP

// https://leetcode.com/problems/predict-the-winner/discuss/96832/C%2B%2B-DP-solution-with-explanation
