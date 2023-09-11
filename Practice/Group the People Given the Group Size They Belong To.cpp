class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < groupSizes.size(); i++)
        {
            int grpSize = groupSizes[i];
            mp[grpSize].push_back(i);
            if (mp[grpSize].size() == grpSize)
            {
                ans.push_back(mp[grpSize]);
                mp[grpSize].clear();
            }
        }

        return ans;
    }
};