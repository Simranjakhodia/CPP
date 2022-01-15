// https://leetcode.com/problems/rotate-image

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1;
        
        while(left < right) {
            
            for(int i = 0; i < right - left; i++) {
                int top = left, down = right;
                int top_left = matrix[top][left + i];
                
                // move bottom-left to top-left
                matrix[top][left + i] = matrix[down - i][left];
                
                // move bottom-right to bottom-left
                matrix[down - i][left] = matrix[down][right - i];
                
                //move top-right to bottom-right
                matrix[down][right - i] = matrix[top + i][right];
                
                //move top-left to top-right
                matrix[top + i][right] = top_left;
                
            }   
            left++; right--;
        }
        
    }
};

// https://www.youtube.com/watch?v=fMSJSS7eO1w
