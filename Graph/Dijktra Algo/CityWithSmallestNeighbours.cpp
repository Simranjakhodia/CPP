// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

class Solution {
public:
    vector<vector<pair<int, int>>> adj;
    vector<pair<int, int>> ans;
    
    bool static cmp(const pair<int, int> p1, const pair<int, int> p2) {
        if(p1.first != p2.first)
            return p1.first < p2.first;
        
        return p1.second > p2.second;
    }
    
    void dijktra(int src, int n, int dT) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> dist(n, INT_MAX);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [prevDist, prev] = pq.top();
            pq.pop();
            
            for(auto it : adj[prev]){
                int next = it.first;
                int nextDist = it.second;
                if(dist[next] > nextDist + dist[prev]) {
                    dist[next] = dist[prev] + nextDist;
                    pq.push({dist[next], next});
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(i != src && dist[i] <= dT)
                cnt++;
        }
        ans.push_back({cnt, src});
    }
    
    int findTheCity1(int n, vector<vector<int>>& edges, int dT) {
        // adj =  vector<vector<pair<int, int>>>(n, vector<pair<int, int>> ());  OR
        adj.resize(n);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        for(int i = 0; i < n; i++) {
            dijktra(i, n, dT);
        }
        
        sort(ans.begin(), ans.end(), cmp);
        
        return ans[0].second;
    }
    
    // mt - 2 : Floyd Warshall 
    
    int findTheCity(int n, vector<vector<int>>& edges, int dT) {
        vector<vector<int>> dist = vector(n, vector<int> (n, 10001));
        for(int i = 0; i < n; i++) dist[i][i] = 0;
        for(vector<int>& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = dist[v][u] = w;
        }
        
        for(int k = 0; k < n; k++) 
            for(int i = 0; i < n; i++) 
                for(int j = 0; j < n; j++) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            
        int minReachable = n, ans = 0;
        for(int i = 0; i < n; i++) {
            int reachable = 0;
            for(int j = 0; j < n; j++)
                if(dist[i][j] <= dT)
                    reachable++;
            if(reachable <= minReachable) {
                minReachable = reachable;
                ans = i;
            }
        }
        return ans;
        
    }

};

// https://www.youtube.com/watch?v=oNI0rf2P9gE
