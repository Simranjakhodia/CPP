// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/


class Solution {
public:
    int f(string word) {
        char c = *min_element(word.begin(), word.end());
        return count(word.begin(), word.end(), c);
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> f_words, res;
        int n = words.size();
        for(auto word : words) f_words.push_back(f(word));
        sort(f_words.begin(), f_words.end());
        
        for(auto q : queries) {
            int idxFirstLarger = upper_bound(f_words.begin(), f_words.end(), f(q)) - f_words.begin();
            res.push_back(n - idxFirstLarger);
        }
        return res;
    }
};

// https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/discuss/1377391/C%2B%2B-Two-Simple-Different-Solutions-Very-Short-and-Clean
