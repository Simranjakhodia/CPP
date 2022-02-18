//  https://www.geeksforgeeks.org/bitmasking-and-dynamic-programming-set-1-count-ways-to-assign-unique-cap-to-every-person/
// https://www.youtube.com/watch?v=Es6vqUOzhPQ

#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<int> capList[101]; // capList[i]'th vector contains the list of persons having a cap with id id
int dp[1025][101];  // dp[i][j] is no of caps we can assign to mask i 2^10 mask combinations
int allmask; // it is used for base case, if all of its bits are set => all N people are wearing the cap 

long long int countWaysUtil(int mask, int i) {
    if(mask == allmask) return 1;   // If all persons wearing a cap so we return 1 
    
    if(i > 100) return 0; // If not everyone is wearing a cap and no caps left so no way left

    if(dp[mask][i] != -1) return dp[mask][i]; // If we already solved this subproblem, return combinations 
    
    // ways when we don't include this cap in our arrangement
    long long int ways = countWaysUtil(mask, i+1);
    
    // size if tota no of people having cap with id i
    int size = capList[i].size();
    
    // assign one by one ith cap to all the possible persons and recur for remaining caps
    for(int j = 0 ; j < size; j++) {
        
        if(mask & (1 << capList[i][j])) continue;  // if person capList[i][j] is already wearing a cap continue;
        else
            ways += countWaysUtil(mask | (1 << capList[i][j]), i + 1);
            ways %= MOD;
        
    }
    return dp[mask][i] = ways;    // save the result and return it
}

void countWays(int n) {
    string temp, str;
    int x;
    getline(cin, str);
    for(int i = 0; i < n; i++) {
        getline(cin, str);
        stringstream ss(str);
        
        // while there are words in the stringstream object ss
        while(ss >> temp) {
            stringstream s;
            s << temp;
            s >> x;
            
            // add the ith person in the list of cap if with id x
            capList[x].push_back(i);
        }
    }
    allmask = (1 << n) - 1 ;// set all n bits as 1
    
    // Initialize all entries in dp as -1
    memset(dp, -1, sizeof dp);
    
    cout << countWaysUtil(0, 1) << endl;
}

int main() {
    int n;
    cin >> n;   
    countWays(n);
    return 0;
}
