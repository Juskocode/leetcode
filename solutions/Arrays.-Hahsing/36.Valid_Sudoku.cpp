class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        std::vector<unordered_set<char>> rows(9), cols(9), boxes(9);
        char num;
        auto exists = [](unordered_set<char>& s, int val)
        {
            return s.insert(val).second;
        };

        for(int i = 0; i < 9; i++)    
            for(int j = 0; j < 9; j++) 
            {
                num = board[i][j];
                if(num == '.')
                    continue;
                if(!exists(rows[i],num) || !exists(cols[j],num) 
                || !exists(boxes[(i/3)*3 + j/3],num))
                return false;
            }
        return true;
    }
};
