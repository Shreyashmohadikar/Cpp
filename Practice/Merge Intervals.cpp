class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        int first = arr[0][0];
        int second = arr[0][1];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i][0] <= second)
            {
                second = max(second, arr[i][1]);
            }
            else
            {
                ans.push_back({first, second});
                first = arr[i][0];
                second = arr[i][1];
            }
        }
        ans.push_back({first, second}); // for last values
        return ans;
    }
};