// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
    struct Comparator {
        bool operator() (const pair<int, string>& lhs,
                        const pair<int, string>& rhs) {
            if(lhs.first != rhs.first)
                return lhs.first > rhs.first;   // put on the top the pair with less frequency
            else 
                return lhs.second < rhs.second; // put on the top the pair with greater lexicography
        };
    };    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map <string, int> count;
        priority_queue< pair<int, string>, vector<pair<int, string>>, Comparator> pq; //  min heap
        for(string& w : words)
            count[w]++;
        
        for(auto c : count) {
            pq.push({c.second, c.first});
            if(pq.size() > k) pq.pop();
        }
        vector<string> res(pq.size());
        int i = pq.size() - 1;
        while(!pq.empty()) {
            res[i--] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};
