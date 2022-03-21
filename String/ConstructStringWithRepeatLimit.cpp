// https://leetcode.com/problems/construct-string-with-repeat-limit/


class Solution {
    struct Comparator {
        bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) {
            return lhs.first < rhs.first;
        };
    };
public:
    string repeatLimitedString(string s, int k) {
        int j = 0;
        unordered_map <char, int> m;
        for(auto ch : s)
            m[ch]++;
        priority_queue<pair<char, int>, vector<pair<char,int>>, Comparator> pq;
        for(auto i : m)
            pq.push(make_pair(i.first, i.second));
        string res = "";
        while(!pq.empty()) {
            pair<char, int> one = pq.top(); pq.pop();
            
            
            int len = min(k, one.second);
            for(int i = 0 ; i < len; i++) 
                res.push_back(one.first);
            
            pair<char, int> two;
            if(one.second - len > 0) {
                if(!pq.empty()) {
                     two = pq.top(); pq.pop();    
                }
                else {return res;}
                res.push_back(two.first);
                pq.push(make_pair(one.first, one.second - len));
                if(two.second - 1 > 0)
                    pq.push({two.first, two.second - 1});
            }
        }
        return res;
    }
};
