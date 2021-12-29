// https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
    public: 
    string removeDuplicateLetters(string s) {
      vector<unsigned int>cnt(26, 0); // only consider lowercase characters
      vector<bool>visited(26, false);
      string res = "";
      for(char ch : s) 
          cnt[ch-'a']++;
      for(char ch : s) {
          cnt[ch-'a']--;
          if(res.empty()) {
              res.push_back(ch);
              visited[ch-'a'] = true; 
              continue;
          }
          if(visited[ch-'a']) continue;
          while(ch < res.back() && !res.empty() && cnt[res.back() -'a'] > 0){
              visited[res.back()-'a'] = false;
              res.pop_back();
          }
          res.push_back(ch);
          visited[ch-'a'] = true;
      }  
      return res;  
    }
};

// https://leetcode.com/problems/remove-duplicate-letters/discuss/76853/4ms-C%2B%2B-solution-use-return-string-as-a-stack
