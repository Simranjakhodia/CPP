//  https://leetcode.com/problems/reorganize-string


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> count;
        priority_queue<pair<int, char>> pq;  // max heap
        string res = "";
        for(char c : s)
            count[c]++;
        for(auto e : count)
            pq.push({e.second, e.first});
        while (!pq.empty()) {
            vector<pair<int, char>> temp;
            for(int i = 0; i <= 1; i++) {
                if(!pq.empty()) {
                    temp.push_back({pq.top().first - 1, pq.top().second});
                    if(res.length() > 0 && res[res.length()-1] == pq.top().second) return "";
                    res += pq.top().second;
                    pq.pop();
                }
            }
            for(auto t : temp) 
                if(t.first)
                pq.push(t);
        }
        return res;
    }
};


// Reference : https://www.youtube.com/watch?v=tGw5GbDekTU
