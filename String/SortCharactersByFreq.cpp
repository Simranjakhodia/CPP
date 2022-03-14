// https://leetcode.com/problems/sort-characters-by-frequency/submissions/


class Solution {
public:
    string frequencySort1(string s) {
        unordered_map<char, int> m; 
        for(char c : s)
           m[c]++;
        
        priority_queue<pair<int, char>> pq; // max heap
        
        for(auto it : m) {
            pq.push({it.second, it.first});
        }
        string res = "";
        while(!pq.empty()) {
            res += string(pq.top().first, pq.top().second);
            /*string ( count, character ) create a string containing character repeated count times  */
    
            pq.pop();
           
        }
        
        return res;
    }   
    
    string frequencySort(string s) {
        int count[256] = {0};
        for(char c : s)
            count[c]++;
       
        sort(s.begin(), s.end(), [&](char a, char b) {
            return count[a] > count[b] || (count[a] == count[b] && a < b); 
        });
        return s;
    }
    
};

// https://leetcode.com/problems/sort-characters-by-frequency/discuss/645688/C%2B%2B-Concise-7-Lines-O(n)-or-Heap-or-No-Custom-Comparator
// https://leetcode.com/problems/sort-characters-by-frequency/discuss/93409/Concise-C%2B%2B-solution-using-STL-sort
