#include <bits/stdc++.h>
using namespace std;

int lis(string s) {
    vector<int> t(26, 0);
    int n = s.size();
    
    int lis = INT_MIN;
    for(int i = 0; i < n; i++) {
        int val = s[i] - 'a';
        int curr = 0;
        
        for(int j = 0; j < val; j++) 
            curr = max(curr, t[j]);
            
        curr++; // to include curr char
        lis = max(lis, curr);
        t[val] = max(t[val], curr);
    }
    return lis;
}

int main() {
    string s = "abzd";
    cout << lis(s);
    return 0;
}

/*

In: abzd
Out: abd, adz of len 3

TC: O(N) SC: O(1)

*/

// https://www.geeksforgeeks.org/length-of-longest-increasing-subsequence-in-a-string/
