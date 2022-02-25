// https://leetcode.com/problems/maximal-rectangle/


class Solution {
public:
    int MAH(vector<int> v, int n) {
        stack<pair<int, int>> s1, s2; // s1 : NSE Left, s2: NSE Right
        vector<int> v1, v2; 
        for(int i = 0; i < n; i++) {
            while(!s1.empty() && s1.top().first >= v[i])
                s1.pop();
            if(s1.empty()) v1.push_back(-1);
            else v1.push_back(s1.top().second);
            s1.push({v[i], i});
            
            while(!s2.empty() && s2.top().first >= v[n - i -1])
                s2.pop();
            if(s2.empty()) v2.push_back(n);
            else v2.push_back(s2.top().second);
            s2.push({v[n - i - 1], n - i - 1});
        }
        reverse(v2.begin(), v2.end());
        int mx = INT_MIN;
        for(int i = 0; i < n; i++) {
            int width = v2[i] - v1[i] - 1;
            int area  = width * v[i];
            mx = max(mx, area);
        }
         
        return mx;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int j = 0; j < cols; j++)
            v.push_back(matrix[0][j] - '0');
        int mx = MAH(v, cols);
        
        for(int i = 1; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else 
                    v[j] += (matrix[i][j] - '0');
            }
            mx = max(mx, MAH(v, cols));
        }
        return mx;
    }
};

// https://www.youtube.com/watch?v=St0Jf_VmG_g
