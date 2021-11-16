// https://leetcode.com/problems/palindrome-number/


class Solution {
public:
   /* bool isPalindrome(int x) {
       // if(x == 0) return true;
        if(x < 0 || x!=0 && x%10 == 0) return false;
        
        int r = x, s = 0;
        while(x>0){
            if(s > INT_MAX/10 || s == INT_MAX/10 && x%10 > 7) return false;
            s = x%10 + s*10;
            x /= 10;
        }
        return (s == r)? true : false;
        
    } */ // 16 ms, faster than 41.90% of C++ online submissions ,  6 MB, less than 31.14% of C++ online submissions
    
    bool isPalindrome(int x){
        if(x < 0 || x!=0 && x % 10 == 0) return false;
        int revHalf = 0, slow = x , fast = x;
        while(fast){
            revHalf = revHalf * 10 + slow % 10;
            slow = slow / 10;
            fast = fast / 100;
        }
        // At this point: slow = 1; fast = 0; revHalf = 12; (assumed x = 121)
        return slow == revHalf || slow == revHalf/10;
    }  // Runtime: 8 ms, faster than 79.84% of C++ online submissions for Palindrome Number.
//Memory Usage: 5.8 MB, less than 91.19% of C++ online submissions
    
};
