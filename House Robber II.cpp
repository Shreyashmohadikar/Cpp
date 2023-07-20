class Solution {
public:

    int f(int idx, vector<int> &nums, vector<int> &dp){
        if(idx < 0 ){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int pick = nums[idx] + f(idx-2, nums, dp);
        int notpick = 0 + f(idx-1, nums, dp);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        vector<int> temp1(nums.begin(), nums.end() - 1);
        vector<int> temp2(nums.begin() + 1, nums.end());
        vector<int> dp1(n-1, -1);
        vector<int> dp2(n-1, -1);
        return max(f(n-2,temp1,dp1), f(n-2,temp2,dp2));
    }
};