// https://leetcode.com/problems/word-break-ii/submissions/


class Solution {

private:
    unordered_set <string> set;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set.clear();
        copy(wordDict.begin(), wordDict.end(), inserter(set, set.end()));
        
        int len = s.size();
        vector<int> dp (len+1, 0);
        dp[0] = 1;
        for(int i = 1 ; i <= len; i++){
            for(int j = i-1; j >= 0; j--) {
                if(dp[j] && set.count(s.substr(j, i-j)) ) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        vector<string> res;
        if(dp[len])
             constructSentence(s, dp, res, 0, "");
        return res;
    }
    
     void constructSentence(string &s, 
                                     vector<int> &dp , 
                                     vector<string>& res,
                                     int pos,
                                     string temp){
        for(int i = pos + 1; i < dp.size(); i++){
            if(dp[i]) {
                 string new_word = s.substr(pos, i-pos);
                if(set.count(new_word)) {
                    if(i + 1 == dp.size()) {
                        res.push_back(temp + new_word);
                        return ;
                    }
                    constructSentence(s, dp, res, i, temp + new_word + " ");
            }
            }
        }
        
    }    
};
