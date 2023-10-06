class Solution
{
public:
    void findComb(int idx, vector<vector<int>> &ans, vector<int> &arr, int target, vector<int> ds)
    {
        if (idx == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        if (target >= arr[idx])
        {
            ds.push_back(arr[idx]);
            findComb(idx, ans, arr, target - arr[idx], ds);
            ds.pop_back();
        }
        findComb(idx + 1, ans, arr, target, ds);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, ans, candidates, target, ds);
        return ans;
    }
};
