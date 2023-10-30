class Solution
{
private:
    int calcSize(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            if (num % 2 == 1)
            {
                sum++;
            }
            num /= 2;
        }
        return sum;
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            int currSize = calcSize(arr[i]);
            pq.push({currSize, arr[i]});
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};