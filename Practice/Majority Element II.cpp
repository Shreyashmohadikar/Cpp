class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int t = n / 3;
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }
        vector<int> ans;
        for (auto it : mp)
        {
            if (it.second > t)
            {
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};