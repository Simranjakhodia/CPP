// https://leetcode.com/problems/super-ugly-number/

class Solution {
public:
   // Brute Force TLE O(kn)
   int nthSuperUglyNumber1(int n, vector<int>& primes) {
        vector<int> idx(primes.size(), 0);
        vector<int> ugly(n, INT_MAX);
        ugly[0] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < primes.size(); j++)
                ugly[i] = min(ugly[i], primes[j]*ugly[idx[j]]);
            for(int j = 0; j < primes.size(); j++)
                idx[j] += (ugly[i] == ugly[idx[j]]*primes[j]);
        }
        return ugly[n-1];
    } 
    // MT-2 Using Priority Queue o(nlogk) TLE
    int nthSuperUglyNumber2(int n, vector<int>& primes) {
        long long top = 0, i = 0, res = -1;
        priority_queue<long long, vector<long long>, greater<long long>> pq = {};
        pq.push(1);
        while(!pq.empty() && i < n){
            top = pq.top();
            res = top;
            pq.pop();
            i++;
            for(auto element : primes) 
                pq.push(top*element);
        
            // to remove duplicates
            while(!pq.empty() && top == pq.top())
                pq.pop();
        }
        return res;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long int> ugly(n, 0);
        vector<long int> value(primes.size(), 0), idx(primes.size(), 0);
        for(int i = 0 ; i < primes.size(); i++) value[i] = primes[i];
        int m;
        ugly[0] = 1;
        for(int i = 1; i < n; i++) {
            m = INT_MAX;
            for(int j = 0; j < primes.size(); j++) {
                if(value[j] < m)
                    m = value[j];
            }
            ugly[i] = m;
            
            for(int j = 0; j < primes.size(); j++) {
                if(m == value[j]) {
                    idx[j]++;
                    value[j] = primes[j]*ugly[idx[j]];
                }
            }
        }
        return ugly[n-1];
     }    
};
