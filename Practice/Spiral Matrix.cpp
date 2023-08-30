class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        if(matrix.size() == 0 || matrix[0].size() == 0){
            return ans;
        }

        int rowStart = 0, colStart = 0;
        int rowEnd = matrix.size()-1, colEnd = matrix[0].size()-1;

        while(rowStart <= rowEnd && colStart <= colEnd){
            //Traverse Right
            for(int i=colStart; i<=colEnd; i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            //Traverse Down
            for(int i=rowStart; i<=rowEnd; i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            //Traverse Left
            if(rowStart <= rowEnd){
                for(int i=colEnd; i>=colStart; i--){
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            //Traverse Up
            if(colStart <= colEnd){
                for(int i=rowEnd; i>=rowStart; i--){
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return ans;
    }
};