class Solution
{
public:
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (dp[i - 1] * 2) % MOD;
        }

        int left = 0, right = n - 1;
        int ans = 0;
        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                ans = (ans + dp[right - left]) % MOD;
                left++;
            }
            else
            {
                right--;
            }
        }
        return ans;
    }
};


// Number of Subsequences That Satisfy the Given Sum Conditi