/// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/


class Solution {
public:
    
    string kthLargestNumber(vector<string>& nums, int k) {
        auto comp = [](const string& a, const string& b) {
        if(a.size() != b.size()) return a.size() > b.size();
        return a > b;
        };
        priority_queue <string, vector<string>, decltype(comp)> pq (comp);   // max heap
        for(string s : nums) {
            pq.push(s);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }  // Time Complexity : O(N log k)
};

/***********   Method 2   *************/
class Solution {
public:
    static bool comp(string& a, string& b) {
        if(a.size() != b.size()) return a.size() < b.size();
        return a < b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), comp);
        return nums[nums.size() - k];
    }
};
