// https://leetcode.com/problems/minimum-height-trees/


class Solution {
public:
    /*
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        vector<unordered_set<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }
        
        queue <int> q;
        for(int i = 0; i < adj.size(); i++) {
            if(adj[i].size() == 1) q.push(i);
        }
        while(n > 2) {
            int len = q.size();
            n = n - len;
            for(int i = 0; i < len; i++) {
                int node = q.front();
                q.pop();
                for(auto &a : adj[node]) {
                    adj[a].erase(node);
                    if(adj[a].size() == 1)
                        q.push(a);
                }
            }
        }
        vector<int> result;
        while(!q.empty()) {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }    // https://www.youtube.com/watch?v=qbpP8GIZiqQ
    
    */
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};
        vector<vector<int>> adj(n);
        vector<int> degrees(n, 0);
        vector<int> res;
        
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degrees[edges[i][0]]++;
            degrees[edges[i][1]]++;
        }
        queue <int> q;
        for(int i = 0 ; i < n; i++) {
            if(degrees[i] == 1) 
                q.push(i);
        }
        while(!q.empty()) {
            res.clear();
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                res.push_back(curr);
                
                for(auto &neighbor : adj[curr]) {
                    degrees[neighbor] --;
                    if(degrees[neighbor] == 1)
                        q.push(neighbor);
                }
            }
        }
        return res;
    }
};

// https://www.geeksforgeeks.org/roots-tree-gives-minimum-height/
