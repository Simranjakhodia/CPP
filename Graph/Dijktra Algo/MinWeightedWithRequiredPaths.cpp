// https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/


class Solution {
public:
    vector<long long> Dijkstra(vector<vector<pair<int, long long>>>& adj, int src) {
        int n = adj.size();
        vector<long long> dist(n, 1e18);
        dist[src] = 0;
        
        priority_queue<pair<long long, int> , vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, src});  
        
        while(!pq.empty()) {
            auto [d, curr] = pq.top();
            pq.pop();
            if(d != dist[curr]) continue;
            for(auto [t, w] : adj[curr]) {
                if(dist[t] > d + w) {
                    dist[t] = d + w;
                    pq.push({dist[t], t});
                }
            }
        }
        return dist;
    }
    
    
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        vector<vector<pair<int, long long>>> adj(n);
        vector<vector<pair<int, long long>>> rev(n);    // graph with reversed edges
        
        for(auto e : edges){
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            rev[v].push_back({u, w});
        }
        
        vector<long long> dist_from_src1 = Dijkstra(adj, src1);
        vector<long long> dist_from_src2 = Dijkstra(adj, src2);  
        vector<long long> dist_to_dst = Dijkstra(rev, dest);
        
        // find smallest weight
        long long ans = 1e18;
        for(int i = 0; i < n; i++) {
            ans = min(ans, dist_from_src1[i] + dist_from_src2[i] + dist_to_dst[i]);
        }
        return ans == 1e18 ? -1 : ans;
    }
};
