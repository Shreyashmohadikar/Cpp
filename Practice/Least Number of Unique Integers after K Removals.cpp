class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (int &it : arr)
        {
            mp[it]++;
        }
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (auto &it : mp)
        {
            pq.push({it.second, it.first});
        }
        while (k)
        {
            auto temp = pq.top();
            pq.pop();
            int count = temp.first;
            int num = temp.second;
            k -= count;
            if (k >= 0)
            {
                continue;
            }
            else
            {
                pq.push({count, num});
                break;
            }
        }
        return pq.size();
    }
};