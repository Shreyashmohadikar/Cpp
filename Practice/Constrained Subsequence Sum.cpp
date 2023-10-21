class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int maxSum = nums[0];
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        //{maxSum, index}
        for (int i = 1; i < nums.size(); i++)
        {
            while (!pq.empty() && i - pq.top().second > k)
            {
                pq.pop();
            }
            int currSum = max(nums[i], nums[i] + pq.top().first);
            maxSum = max(maxSum, currSum);
            pq.push({currSum, i});
        }
        return maxSum;
    }
};