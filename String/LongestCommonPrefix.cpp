// https://leetcode.com/problems/longest-common-prefix/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0, minLength = 10000;
        string min_str = "";
        for(int i = 0; i < strs.size(); i++){
            int l = strs[0].length();
            if ( minLength > l ) 
            { 
                minLength = l;
                min_str = strs[i];
            }        
        }   
        for(int i = 0 ; i < minLength; i++){
            for(int j = 0 ; j < strs.size(); j++){
                if(min_str[i] != strs[j][i] )
                    return min_str.substr(0, count);
            }
            count++;
        }
        return min_str.substr(0, count);
    }
};
