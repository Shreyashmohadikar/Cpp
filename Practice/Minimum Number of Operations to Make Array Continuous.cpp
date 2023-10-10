class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int arrSize = nums.size() - 1;
        int uniqueLen = unique(nums.begin(), nums.end()) - nums.begin();
        int L = 0, R = 0, currWindowSize = 1;

        while (R < uniqueLen)
        {
            if (L == R)
            {
                R++;
            }
            else if (nums[R] - nums[L] > arrSize)
            {
                L++;
            }
            else
            {
                currWindowSize = max(currWindowSize, R - L + 1);
                R++;
            }
        }
        return arrSize - currWindowSize + 1;
    }
};