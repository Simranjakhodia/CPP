//  https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1

/*

Time Complexity : O(32 * R * log(C))    // By using Binary Search

Space Complexity : O(1)

*/


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){
          int start = 0, end = 2000;
          while(start <= end) {
              int center = start + (end - start)/2;
              int count = 0;
              int n = r * c;
              for(int i = 0; i < r; i++) {
                  int l = 0, h = c-1;
                  while(l <= h) {
                      int mid = l + (h-l)/2;
                      if(matrix[i][mid] <= center)
                         l = mid + 1;
                      else
                         h = mid - 1;
                  }
                  count = count + l;
              }
                if(count > n / 2)
                    end = center - 1;
                else
                    start = center + 1;
          }
          return start;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}
// } Driver Code Ends
