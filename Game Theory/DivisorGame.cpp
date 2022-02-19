// https://leetcode.com/problems/divisor-game/




class Solution {
public:
    bool divisorGame(int n) {
        vector<int> memo(n+1, 0);
        return helper(n, memo);
    }
private:
    bool helper(int n, vector<int>& memo) {
      /*  if(n == 2){
            memo[2] = 1; return true;
        }
        if(n == 3){
            memo[3] = -1; return false;
        } */
        if(memo[n] != 0) return memo[n] == 1;
        
        for(int i = 1; i <= n/2; i++) {
            if(n % i == 0) {
                if(!helper(n - i , memo)) {
                    memo[n] = 1;
                    return true;
                }
            }
        }
        memo[n] = -1;
        return false;
    }
};


/*  when helper(n - i) -> true it means other player won => which means we lost
hence we are using negation here.
res=!helper(n - i) which will be true if other player loses
and just break loop now with !res && i <= n / 2 condition because we will consider only optimal answer  */

// https://leetcode.com/problems/divisor-game/discuss/274566/just-return-N-2-0-(proof)
