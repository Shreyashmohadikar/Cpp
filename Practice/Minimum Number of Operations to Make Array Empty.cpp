class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto &it : nums)
        {
            mp[it]++;
        }
        int ans = 0;
        for (auto &it : mp)
        {
            int count = it.second;
            if (count == 1)
            {
                return -1;
            }
            else if (count % 3 == 0)
            {
                ans += count / 3;
            }
            else
            {
                ans += (count / 3) + 1;
            }
        }
        return ans;
    }
};