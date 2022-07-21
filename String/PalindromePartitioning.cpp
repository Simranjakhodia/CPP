// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(string s, int i, int j) {
        if(i == j) return true;
        if(i > j) return true;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string s, int i, int j, vector<vector<int>>& t) {
        if(i >= j) return 0;
        if(isPalindrome(s, i, j) == true) return 0;
        if(t[i][j] != -1) return t[i][j];
        int mn = INT_MAX, left = 0, right = 0;
        for(int k = i; k <= j-1; k++) {
            if(t[i][k] != -1) 
                left = t[i][k];
            else 
                left = solve(s, i, k, t);
            if(t[k+1][j] != -1)
                right = t[k+1][j];
            else right = solve(s, k+1, j, t);
            int temp = 1 + left + right;
            if(temp < mn)
                mn = temp;
        }
        return t[i][j] = mn;
    }
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>> t(n, vector<int>(n, -1));
        
        return solve(str, 0, n-1, t);
    }
};


// Youtube : Aditya Verma Dynamic Programming Playlist

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
