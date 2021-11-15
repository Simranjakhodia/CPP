class Solution {
public:
    string longestPalindrome(string s) {
       if(s.empty() || s.length() < 1) 
           return "";
        if(s.length() == 1)
            return s;
        int left = 0, maxLen = 0, right = 0;
        for(int i = 0; i < s.length(); i++){
            int len1 = expandAroundCenter(s, i, i);   // odd
            int len2 = expandAroundCenter(s, i, i+1); // even 
            int len = max(len1, len2);
            if(len > maxLen){
                maxLen = len;
                left = i - (len - 1) / 2;
                right = i + len / 2;
            }
             
        }
        
        return s.substr(left, maxLen);
            
    }
    
    int expandAroundCenter(string s, int left, int right){
        int L = left, R = right;
        while( L >= 0 && R < s.length() && s[L] == s[R] ){
            L--;
            R++;
        }
        return R - L - 1 ; // LENGTH OF SUBSTRING.
    }
};

// https://www.youtube.com/watch?v=LgG2Km9GvJw
// https://gist.github.com/vrege/6c7c1453069a15c8b4c37a3e90797136
// https://leetcode.com/problems/longest-palindromic-substring/
