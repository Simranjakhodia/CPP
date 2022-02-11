// https://leetcode.com/problems/text-justification/

class Solution {
public:
    
    string leftJustify(vector<string>& words, int tot_spaces, int i, int j) {
        
        int spacesOnRight = tot_spaces - (j - i - 1);
        string res = words[i];
        for(int k = i + 1; k < j; k++) {
            res += " " + words[k];
        }
        res.append(spacesOnRight, ' ');
        return res;
        
    }
    
    string middleJustify(vector<string>& words, int tot_spaces, int i, int j) {
        
        int spaces = tot_spaces / (j - i - 1);  // int noOfWords = j - i;
        int extra_spaces = tot_spaces % (j - i - 1);
        
        string res = words[i];
        for(int k = i + 1; k < j; k++) {
            
            res.append(spaces, ' ');
            
            if(extra_spaces) {
                res += ' '; 
                extra_spaces --;
            }
            res.append(words[k]);
        }
        return res;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0, j ;
        for(; i < words.size();){
            
            int linelength = words[i].length();
        
            for(j = i + 1; 
                j < words.size() && linelength + words[j].length() + (j-i-1) < maxWidth;
                j++) {
                
                linelength += words[j].length();
            }
           int tot_spaces = maxWidth - linelength;
          //  necessary_spaces = j - i - 1; // or (n - 1)
          //  spaces = tot_spaces / necessary_spaces;
         //   extra_spaces = tot_spaces % necessary_spaces;
            int n = j - i; // no of words in a line
            if(n == 1 || j >= words.size()) {
                res.push_back(leftJustify(words, tot_spaces, i, j));
            } else {
                res.push_back(middleJustify(words, tot_spaces, i, j));
            }
            i = j;
        }
        return res;
    }
};
