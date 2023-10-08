class Solution
{
private:
    int f(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int takeBoth = (nums1[i] * nums2[j]) + f(i - 1, j - 1, nums1, nums2, dp);
        int take1 = f(i - 1, j, nums1, nums2, dp);
        int take2 = f(i, j - 1, nums1, nums2, dp);
        return dp[i][j] = max({takeBoth, take1, take2});
    }

public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        int ans = f(n1 - 1, n2 - 1, nums1, nums2, dp);
        if (ans)
            return ans;

        bool allNega1 = true, allNega2 = true;

        int min1 = INT_MAX, max1 = INT_MIN;
        int min2 = INT_MAX, max2 = INT_MIN;

        for (auto it : nums1)
        {
            if (it > 0)
                allNega1 = false;
            min1 = min(min1, it);
            max1 = max(max1, it);
        }
        for (auto it : nums2)
        {
            if (it > 0)
                allNega2 = false;
            min2 = min(min2, it);
            max2 = max(max2, it);
        }

        if (allNega1)
        {
            return max1 * min2;
        }
        if (allNega2)
        {
            return min1 * max2;
        }
        return 0;
    }
};