class Solution
{
private:
    int smoothen(vector<vector<int>> &img, int x, int y)
    {
        int m = img.size();
        int n = img[0].size();
        int sum = 0;
        int count = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int new_i = i + x;
                int new_j = j + y;
                if (new_i >= 0 && new_j >= 0 && new_i < m && new_j < n)
                {
                    sum += img[new_i][new_j];
                    count++;
                }
            }
        }
        return sum / count;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = smoothen(img, i, j);
            }
        }
        return ans;
    }
};