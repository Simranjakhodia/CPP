
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> path;
vector<pair<int, int>> ans;
bool isSafe(vector<vector<int>>& arr, int src_i, int src_j, vector<vector<bool>>& vis) {
    if(src_i < 0 || src_i >= arr.size() || src_j < 0 || src_j >= arr[0].size() || arr[src_i][src_j] == 0 || vis[src_i][src_j] == true)
        return false;
        
    return true;
}

void  dfs(vector<vector<int>>& arr, int src_i, int src_j, int dest_i, int dest_j, vector<vector<bool>>& vis, int &minDist, int dist) {
    
    if(src_i == dest_i && src_j == dest_j) {
        if(minDist > dist) {
            minDist = dist;
            ans = path;
        }
        return;
    }
    vis[src_i][src_j] = true;
    path.push_back({src_i, src_j});
    if(isSafe(arr, src_i + 1, src_j, vis))  // down
        dfs(arr, src_i + 1, src_j, dest_i, dest_j,vis, minDist, dist+1);
     
    if(isSafe(arr, src_i, src_j+1, vis))  // right
        dfs(arr, src_i, src_j+1, dest_i, dest_j, vis,minDist, dist+1);
        
    if(isSafe(arr, src_i - 1, src_j, vis))   // up
        dfs(arr, src_i - 1, src_j, dest_i, dest_j, vis,minDist, dist+1);
        
    if(isSafe(arr, src_i, src_j-1, vis))  // left
        dfs(arr, src_i, src_j-1, dest_i, dest_j,vis, minDist, dist+1);
    
    vis[src_i][src_j] = false;
    path.pop_back();
}

void bfsMaze(vector<vector<int>>& arr, int src_i, int src_j, int dest_i, int dest_j) {
    
    int m = arr.size(), n = arr[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int dist = INT_MAX;
    dfs(arr, src_i, src_j, dest_i, dest_j, vis, dist, 0);
    if(dist == INT_MAX) {
        cout << "Path doesnt exist" << endl;
    }
    else {
        cout << "Shortest Path Length = " << dist <<  endl;
    }
    return;
}
int main() {

    vector<vector<int>> arr =
                 {{1, 1, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
  
  
  bfsMaze(arr, 0, 0, 3, 4);
  cout << endl << "Path is => " << endl;
  
  for(auto p : ans) {
      cout << p.first << "," << p.second << endl;
  }
  
  return 0;
}


// https://www.geeksforgeeks.org/shortest-path-in-a-binary-maze/

// TC : O(4 ^ mn) 
// SC : O(mn)
