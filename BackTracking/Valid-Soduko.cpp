// https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
           int n = board[0].size();
           unordered_set<char> rowSet[n];
           unordered_set<char> columnSet[n];
           unordered_set<char> squareSet[n];
            
           for(int i =0; i < n; i++) {
               for(int j = 0; j < n; j++) {
                   char c = board[i][j];
                   if(c == '.') continue;
                   int k = (i / 3)*3  + (j / 3);   // i: rows; j: columns
                   if(rowSet[i].count(c) || columnSet[j].count(c) || squareSet[k].count(c))
                       return false;
                   rowSet[i].insert(c);
                   columnSet[j].insert(c);
                   squareSet[k].insert(c);
               }
           }
        
        return true;
    }
};

// https://www.youtube.com/watch?v=FWAIf_EVUKE
