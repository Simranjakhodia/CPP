//  https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static bool comp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
        if(a.first != b.first)
            return a.first > b.first;
        return a.second.first < b.second.first;
    }
    int countSetBits(int n) {
        int count = 0;
        while(n) {
            if(n & 1) count++;
            n = n >> 1;
        }
        return count;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        pair<int, pair<int, int>> v[n];
        for(int i = 0; i < n; i++) 
            v[i] = {countSetBits(arr[i]), {i, arr[i]}};
            
        sort(v, v + n, comp);
        for(int i = 0; i < n; i++) {
            arr[i] = v[i].second.second;
        }
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
