///  https://leetcode.com/problems/maximum-compatibility-score-sum/submissions/



class Solution {
public:
    int score(vector<int>& students, vector<int>& mentors) {
        int ans = 0;
        for(int i = 0; i < students.size(); i++) 
            if(students[i] == mentors[i]) ans++;
        
        return ans;
    }
    
    int makeCombinations(vector<vector<int>>& students, vector<vector<int>>& mentors, int i, int mask) {
        if(i == students.size()) 
            return 0;
        int ans = 0;
        
        // Try all possible combinations with available mentors for i-th student
        for(int j = 0; j < mentors.size(); j++) {
            if(((mask >> j) & 1) == 0) {             // this mentor is not taken
                int new_mask = (mask | (1 << j));   // set this mentor as taken
                ans = max(ans, score(students[i], mentors[j]) + makeCombinations(students, mentors, i + 1, new_mask));
            }
        }
        return ans;    
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        return makeCombinations(students, mentors, 0, 0);
    }
};


// https://leetcode.com/problems/maximum-compatibility-score-sum/discuss/1360742/C%2B%2B-DP-%2B-Bitmask-or-4ms
