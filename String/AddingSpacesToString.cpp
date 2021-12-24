// https://leetcode.com/problems/adding-spaces-to-a-string/submissions/


class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(j < spaces.size() && spaces[j] == i) {res += " "; res+=s[i];j++;}
            else if (j == spaces.size()) {res = res + s.substr(i);break;}
            else res += s[i];
        }
        return res;
    }
};


/* 
Do res+=s[i] and res+=" " instead of res=s[i]+res and res = res+ " " or you will get TLE /MLE.
res = s[i] + res and res = " " + res are very inefficient. You are creating new strings over and over again.
res += s[i] only appends s[i] to res (it's the same as res.push_back(s[i])), while res = s[i] + res creates a new string.
*/
