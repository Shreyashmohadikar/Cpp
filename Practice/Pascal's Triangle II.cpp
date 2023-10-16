class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>> pascal;

        for (int row = 0; row <= rowIndex; row++)
        {
            vector<int> temp(row + 1, 1);
            for (int i = 1; i < row; i++)
            {
                temp[i] = pascal[row - 1][i] + pascal[row - 1][i - 1];
            }
            pascal.push_back(temp);
        }
        return pascal.back();
    }
};