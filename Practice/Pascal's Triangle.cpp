class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=0; row<numRows; row++){
            vector<int> temp(row + 1, 1);
            for(int j=1; j<row; j++){
                temp[j] = ans[row-1][j-1] + ans[row-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

//////////////////////
//Using Recursion


class Solution {
public:
    vector<vector<int>> pascal(int row, int numRows, vector<vector<int>> &ans){
        if(row == numRows){
            return ans;
        }
        vector<int> temp(row + 1, 1);
        for(int j=1; j<row; j++){
            temp[j] = ans[row-1][j-1] + ans[row-1][j]; 
        }
        ans.push_back(temp);
        return pascal(row+1, numRows, ans);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        return pascal(0, numRows, ans);
    }
};