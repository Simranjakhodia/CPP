// https://leetcode.com/problems/daily-temperatures/submissions/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        //approach :  nearest greater element to right 
        int n = temp.size();
        vector<int> v;
        stack<pair<int,int>> s;
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && s.top().first <= temp[i])
                s.pop();
            if(s.empty())
                v.push_back(0);
            else v.push_back(s.top().second - i);
            s.push({temp[i], i});
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
