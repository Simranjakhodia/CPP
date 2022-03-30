//  https://leetcode.com/problems/find-eventual-safe-states/


class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& vis, int src) {
        if( vis[src] > 0) return vis[src] == 2;
        vis[src] = 1;
        for(int node : graph[src]) {
            if(vis[node] == 2) continue;
            if(vis[node] == 1 || !dfs(graph, vis, node))
                return false;
        }
        vis[src] = 2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis (graph.size());
        vector<int> res;
        for(int i = 0 ; i < graph.size(); i++){
            if(dfs(graph, vis, i))
               res.push_back(i);
        }
        for(int i = 0; i < graph.size(); i++)
            cout << vis[i] << " ";            // 1 1 2 1 2 2 2  
        return res;
    }
};
