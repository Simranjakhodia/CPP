//  https://leetcode.com/problems/find-k-pairs-with-smallest-sums/


class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if(nums1.empty() || nums2.empty() || k <= 0) return res;
        priority_queue <pair<int, pair<int, int>>> pq;
        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) pq.push({sum, {nums1[i], nums2[j]}});
                else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                }
                else break;
            }
        }
        while(!pq.empty()) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// o(m*n*log k) ; m = size of nums1 ; n = size of nums2 ; log k for inserting k elements into maxheap

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/596658/C%2B%2B-solution-with-diagram-explaination-for-beginners

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84607/Clean-16ms-C%2B%2B-O(N)-Space-O(KlogN)-Time-Solution-using-Priority-queue
