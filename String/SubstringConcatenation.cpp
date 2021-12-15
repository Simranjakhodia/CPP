// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].length();
        int substr_len = word_len * words.size();
        vector<int> res;
       if(words.size() == 0 || substr_len > s.length()) return res;
        map<string, int> wordMap;
        for(string word : words)
            wordMap[word]++;
        for(int i = 0; i <= s.length() - substr_len; i++){
            map<string, int> wordsUsedMap;
            for(int j = i; j < i + substr_len; j = j + word_len){
                string curr = s.substr(j, word_len);
                if(wordMap.find(curr) == wordMap.end())
                    break;
                wordsUsedMap[curr]++;
                if(wordsUsedMap[curr] > wordMap[curr])
                    break;
            }
            if(wordsUsedMap == wordMap)
                res.push_back(i);
        }
            return res;
    }
};
