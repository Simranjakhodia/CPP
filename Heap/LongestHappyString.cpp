// https://leetcode.com/problems/longest-happy-string/submissions/


class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;  // max heap
        string res = "";
        if(a)pq.push({a, 'a'});
        if(b)pq.push({b, 'b'});
        if(c)pq.push({c, 'c'}); 
        while(pq.size() > 1) {
            pair<int, char> one = pq.top(); pq.pop();
            pair<int, char> two = pq.top(); pq.pop();
            if(one.first >= 2){
                res.push_back(one.second);
                res.push_back(one.second);
                one.first -= 2;
            }
            else {
                res.push_back(one.second);
                one.first -= 1;
            }
            if(two.first >= 2 && two.first >= one.first){
                res.push_back(two.second);
                res.push_back(two.second);
                two.first -= 2;
            }
            else {
                res.push_back(two.second);
                two.first -= 1;
            }
            if(one.first > 0) pq.push(one);
            if(two.first > 0) pq.push(two);
        }
        if(pq.empty()) return res;
        if(pq.top().first >= 2) {
           res.push_back(pq.top().second);
           res.push_back(pq.top().second); 
        }https://www.youtube.com/watch?v=ufSbR9kVtM8
        else
            res.push_back(pq.top().second);
        return res;
    }
};


// Logic ref: https://www.youtube.com/watch?v=ufSbR9kVtM8
