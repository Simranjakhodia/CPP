// https://www.youtube.com/watch?v=0ACfAqs8mm0 


class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj, int n, int src, vector<int>& color) {
         queue<int> q;
         q.push(src);
         color[src] = 1;
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto e : adj[curr]) {
                if(color[e] == color[curr])
                    return false;
                if(color[e] == -1) {   // unvisited node
                    color[e] = 1 - color[curr];
                    q.push(e);
                }
            }
        }
        return true;
           
    }
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> color (n + 1, -1);
        
        for(int i = 0 ; i < dislikes.size(); i++) {
            int u = dislikes[i][0];
            int v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) 
                if(!isBipartite(adj, n, i, color))
                    return false;    
        }
        return true;
    }
};


// https://www.youtube.com/watch?v=0ACfAqs8mm0
