class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}; 
        int col[9][9] = {0};
        int box[9][9] = {0};
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    int boxIdx = (i/3)*3 + (j/3);
                    if(row[i][num] || col[j][num] || box[boxIdx][num]){
                        return false;
                    }
                    else{
                        row[i][num] = col[j][num] = box[boxIdx][num] = 1;
                    }
                }
            }
        }
        return true;
    }
};
