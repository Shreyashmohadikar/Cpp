class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> onesRow, onesCol, zerosRow, zerosCol;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    onesRow[i]++;
                    onesCol[j]++;
                }
                else{
                    zerosRow[i]++;
                    zerosCol[j]++;
                }
            }
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diff[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }
        return diff;
    }
};



//////////////////////////

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> Row, Col;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                Row[i] += grid[i][j];
                Col[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                diff[i][j] = 2 * (Row[i] + Col[j]) - m - n;
            }
        }
        return diff;
    }
};