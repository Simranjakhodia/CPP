// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        
        // sort events by start time
        sort(events.begin(), events.end());  
        
        int res = 0, i = 0;
        int n = events.size();
        
        // priority queue contains all events which have already started but not ended
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int d = 1; d < 100000; d++) {
            
            // remove all events which are already over
            while(!pq.empty() && pq.top() < d)
                pq.pop();
            
            // insert deadlines of all events which start today
            while(i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            // we attend the event which starts today and has smallest endtime
            if(!pq.empty()) {
                pq.pop();
                ans++;
            }
            // if all events are processed then stop
            if(pq.empty() && i == n)
                break;
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/1304132/Priority-Queue_Step-by-Step-explanation
