class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int> ans;
        vector<int> start, end;

        for (auto it : flowers)
        {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (auto time : people)
        {
            int startidx = upper_bound(start.begin(), start.end(), time) - start.begin();
            int endidx = lower_bound(end.begin(), end.end(), time) - end.begin();
            ans.push_back(startidx - endidx);
        }
        return ans;
    }
};