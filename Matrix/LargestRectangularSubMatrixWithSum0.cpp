// Largest rectangular sub-matrix whose sum is 0
https://practice.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1


class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      int r = a.size(), c = a[0].size();
      
      int left, right, up, down;
      left = right = up = down = 0;
      
      for(int i = 0; i < c; i++){
          vector<int> v(r, 0);
          
          for(int j = i; j < c; j++){
              for(int k = 0; k < r; k++) 
                  v[k] += a[k][j];
              
              unordered_map<long long, int> mp;
              mp[0] = -1;
              
              int leftv = 0, rightv = 0;
              long long sum = 0;
              
              for(int k = 0; k < r; k++) {
                  sum += v[k];
                  
                  if(mp.count(sum)) {
                      if((k - mp[sum]) > (rightv - leftv )) {
                          rightv = k+1;
                          leftv = mp[sum]+1;
                      }
                  }
                  else 
                        mp[sum] = k;
              }
              
              if((j - i + 1)*(rightv - leftv) > (right - left) * (down - up)) {
                  up = leftv;
                  down = rightv;
                  left = i;
                  right = j+1;
              }
          }
      }
      vector<vector<int>> res;
      for(int i = up; i < down; i++) {
          vector<int> arr;
          for(int j = left; j < right; j++) {
              arr.push_back(a[i][j]);
          }
          res.push_back(arr);
      }
      return res;
  }
};

