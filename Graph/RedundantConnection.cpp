// https://leetcode.com/problems/redundant-connection/


class Solution {
public:
    // MT 1 DFS Traversal O(N^2) time complexity; O(N) space complexity
    vector<int> findRedundantConnection2(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<bool> vis (n+1, false);
        vector<vector<int>> graph(n + 1);
        for(auto &edge : edges) {
            fill(vis.begin(), vis.end(), false);
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            if(dfs(graph, vis, edge[0])) return edge;
        }
        return {};
    }
    
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, int u, int parent = -1) {
        if(vis[u]) return true; // there exists a cycle coz of this edge;
        vis[u] = true;
        
        for(int i = 0; i < graph[u].size(); i++) 
            if(graph[u][i] != parent &&  dfs(graph, vis, graph[u][i], u))  
                    return true;
        return false;
    } 
    
    // MT 2 : Disjoint Union Find
    int find(vector<int> parent, int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent, parent[u]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for(auto edge : edges) {
            int x = find(parent, edge[0]);
            int y = find(parent, edge[1]);
            if(x == y) return {edge[0], edge[1]};
            /* take union */
            parent[x] = y;    
        }
        return {};
    }
    
};


// https://leetcode.com/problems/redundant-connection/discuss/1295887/Easy-Solution-w-Explanation-or-All-Possible-Approaches-with-comments
