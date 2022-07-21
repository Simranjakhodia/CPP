/*
Question Asked in GamesKraft OA 

For a string s and an integer k, a selection of substrings is valid if the following conditions are met:
  * the length of each substring is greater than or equal to k
  * each substring is a palindrome.
  * no two substrings overlap
  
  Detrmine maximum number of valid substrings that can be formed from s.
  
  eg : 
  
  input : string s = "aababaabce", int k = 3;
  output : 2 (i.e. aba, baab)
  
  explanation: 
  case1 : (aababaa) 1
  case2 : (aba, baab) 2   Ans.
*/


#include<bits/stdc++.h>
using namespace std;

int solve(string s, int k) {
    int n = s.size();
    vector<vector<bool>> t(n, vector<bool>(n, false));
    for(int i = 0; i < n; i++)
        t[i][i] = 1;
        
    for(int i = 1; i < n; i++)
        t[i-1][i] = s[i-1] == s[i];
        
    for(int len = 3; len <= n; len++) 
        for(int i = 0, j = len-1; j < n; i++, j++)  
            t[i][j] = s[i] == s[j] && t[i+1][j-1];
            
    int res = 0;
    int last = -1;
    for(int end = 0; end < n; end++) {
        for(int start = end; start > last; start--) {
            if(t[start][end] && (end - start + 1) >= k) {
                res++;
                cout << s.substr(start, end-start+1) << endl;
                last = end;
                break;
            }
        }
    }
    return res;
}
int main() {
    string a = "aababaabce";
    cout << solve(a, 3);
}
