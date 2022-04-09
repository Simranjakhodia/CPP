//  https://leetcode.com/problems/path-with-minimum-effort/


class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
            
        vector<vector<int>> effort(m, vector<int> (n, INT_MAX));
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0}); 
        effort[0][0] = 0;
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pq.empty()) {
            int dist = pq.top()[0];
            int row = pq.top()[1];
            int col = pq.top()[2];
            
            pq.pop();
            
            if(dist > effort[row][col]) continue;
            if(row == m-1 && col == n-1) return dist;
            for(auto d : dir){
                int newRow = row + d[0];
                int newCol = col + d[1];
                
                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    int newDist = max(dist, abs(heights[newRow][newCol] - heights[row][col]));
                    
                    if(newDist < effort[newRow][newCol]){
                        effort[newRow][newCol] = newDist;
                        pq.push({newDist, newRow, newCol});
                    }
                }
            }
        }
        return 0;
    }
};


// https://www.youtube.com/watch?v=FabSLaGu0NI
// https://leetcode.com/problems/path-with-minimum-effort/discuss/1272698/C%2B%2B-Easy-to-understand-dijikstra-solution-using-priority-queues
