// https://leetcode.com/problems/nim-game/


class Solution {
public:
    bool canWinNim(int n) {   // MT-1
        return (n % 4 != 0);
    }
    
  /*  bool canWinNim(int n) {
        vector<int>memo(n+1, 0);
        return helper(n, memo);
    }
private:
    bool helper(int n, vector<int>& memo) {
        if(n <= 3) return true;
        if(memo[n] != 0) return memo[n] == 1;

        
        for(int i = 1; i <= 3; i++) {
            if(!helper(n - i, memo)) {
                memo[n] = 1;
                return true;
            }
        }
        memo[n] = -1;
        return false;
    }
    
    */
};
