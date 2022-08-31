//  https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	
	long long solve(char keypad[4][3], int i, int j, int n, vector<vector<vector<long long>>>& dp) {
	    
	    if(i < 0 || i >= 4 || j < 0 || j >= 3) 
	        return 0;
	        
	    if(keypad[i][j] == '*' || keypad[i][j] == '#')
	        return 0;
	    
	    if(n == 1)
	        return 1;
	        
	    if(dp[i][j][n] != -1)
	        return dp[i][j][n];
	        
	    return dp[i][j][n] = solve(keypad, i, j, n-1, dp) + solve(keypad, i+1, j, n-1, dp) +
	    solve(keypad, i-1, j, n-1, dp) + solve(keypad, i, j-1, n-1, dp) + solve(keypad, i, j+1, n-1, dp);
	}
	long long getCount(int n)
	{
		char keypad[4][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}, {'*','0', '#'}};
		
		long long count = 0;
		
		vector<vector<vector<long long>>>dp (4, vector<vector<long long>>(3, vector<long long>(n+1, -1)));
		for(int i = 0; i < 4; i++) {
		    for(int j = 0; j < 3; j++) {
		        if(keypad[i][j] != '*' && keypad[i][j] != '#') {
		            count += solve(keypad, i, j, n, dp);
		        }
		    }
		}
		return count;
	}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends


