// https://leetcode.com/problems/remove-k-digits/


class Solution {
public:
    // Memory Limit Exceeded
   /* string removeKdigits(string num, int k) {
        if(num.length() == k) return "0";
        
        stack<char> s;
        for(int i = 0; i < num.length(); i++) {
            while(!s.empty() && k && s.top() > num[i]) {
                s.pop();
                k--;
            }
            s.push(num[i]);
        }
        while(k > 0){
            s.pop();
            k--;
        }
        string ans = "";
        while(!s.empty()) {
            ans = s.top() + ans;
            s.pop();
        }
        
        while(ans.size() > 1 && ans[0] == '0')
            ans.erase(0,1);
        
        
        return ans;
    } */
    
     string removeKdigits(string num, int k) {
         string ans = "";
         for(auto &i : num) {
             while(ans.size() && k && ans.back() > i) {
                 ans.pop_back();
                 k--;
             }
             if(ans.size() || i != '0') ans.push_back(i);
         }
         while(k-- && ans.size()) {
             ans.pop_back();
         }
         return ans.size() ? ans : "0";
     }
};

// https://leetcode.com/problems/remove-k-digits/discuss/1779378/Daily-LeetCoding-Challenge-February-Day-18
