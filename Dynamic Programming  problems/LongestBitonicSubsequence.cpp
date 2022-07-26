
// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

	int LongestBitonicSequence(vector<int>arr)
	{
	    
        int n = arr.size();
        vector<int> dp1(n, 1);  // forward increasing
        vector<int> dp2(n, 1);  // backward increasing
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j])
                    dp1[i] = max(dp1[i], 1 + dp1[j]);
            }
        }
        for(int i = n-1; i >= 0; i--) {
            for(int j = i+1; j < n; j++) {
                if(arr[i] > arr[j])
                    dp2[i] = max(dp2[i], 1 + dp2[j]);
            }
        }
        int mx = 0;
        for(int i = 0; i < n; i++) {
            mx = max(mx, dp1[i] + dp2[i] - 1);
        }
	    return mx;
	}
  
  // https://www.youtube.com/watch?v=y4vN0WNdrlg
