//  https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle2948/1?utm_source=youtube&utm_medium=collab_anujbhaiya_description&utm_campaign=maximum-sum-rectangle


class Solution {
  public:
    int kadane(vector<int>& v, int r) {
        int maxSum = INT_MIN, sum = 0;
        for(int i = 0; i < r; i++) {
            sum = max(sum + v[i], v[i]);
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
    int maximumSumRectangle(int r, int c, vector<vector<int>> m) {
       vector<int> v(r, 0);
       int res = INT_MIN;
       for(int cStart = 0; cStart < c; cStart++) {
           fill(v.begin(), v.end(), 0);
           for(int cEnd = cStart; cEnd < c; cEnd++) {
               for(int i = 0; i < r; i++)
                    v[i] += m[i][cEnd];
                    
                res = max(res, kadane(v, r));
           }
       }
       
       return res;
    }
};

// TC : O(C*C*(R + R)) = O(C*C*R)
// SC : O(R)


// https://practice.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1
// https://practice.geeksforgeeks.org/problems/max-sum-submatrix2725/1


// https://www.youtube.com/watch?v=mKluyW4YFvs&ab_channel=AnujBhaiya
