class Solution
{
public:
    void findComb(int idx, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds); 
            return;
        }
        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx && arr[i] == arr[i - 1])
            {
                continue;
            }
            if (arr[i] > target)
            {
                break;
            }
            ds.push_back(arr[i]);
            findComb(i + 1, arr, target - arr[i], ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, candidates, target, ans, ds);
        return ans;
    }
};

// Given a collection of candidate numbers (candidates) and a target number (target),
// find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// do not repeat pattern , sort it, recursion happens or could happen for differnt indexes