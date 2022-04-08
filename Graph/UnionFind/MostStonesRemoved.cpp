// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

class Solution {
    vector<int> parent;
    vector<int> rnk;
    int count;
public:
    int find(int x){
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unionf(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return;
        if(rnk[px] <= rnk[py]){
            parent[px] = py;
            rnk[py]++;
        } else {
            parent[py] = px;
            rnk[px]++;
        }
        count--;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rnk.resize(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            rnk[i] = 0;
        }
        
        count = n;  // no of groups 
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                    unionf(i, j);
            }
        }
        return n - count;
    }
};

// https://www.youtube.com/watch?v=y-rfZ_ToHv8
