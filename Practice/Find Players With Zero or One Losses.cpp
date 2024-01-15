class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        int n = matches.size();
        unordered_map<int, int> win;
        unordered_map<int, int> lose;
        vector<vector<int>> ans;
        vector<int> list1, list2;

        for (int i = 0; i < n; i++)
        {
            win[matches[i][0]]++;
            lose[matches[i][1]]++;
        }
        for (auto &it : win)
        {
            if (!lose.count(it.first))
            {
                list1.push_back(it.first);
            }
        }
        for (auto &it : lose)
        {
            if (it.second == 1)
            {
                list2.push_back(it.first);
            }
        }
        sort(list1.begin(), list1.end());
        sort(list2.begin(), list2.end());

        ans.push_back(list1);
        ans.push_back(list2);
        return ans;
    }
};
// list 1 - no lost at all
// list 2 - lost exactly one