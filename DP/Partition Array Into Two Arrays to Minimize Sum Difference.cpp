#include <vector>
#include <algorithm>

class Solution {
public:
    bool f(int n, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0){
            return dp[n][target] = true;
        }
        if(n == 0){
            return dp[n][target] = (nums[n] == target);
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        bool notTake = f(n-1, target, nums, dp);
        bool take = false;
        if(target >= nums[n]){
            take = f(n-1, target - nums[n], nums, dp);
        }
        return dp[n][target] = (take || notTake);
    }
    int minimumDifference(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totalSum += nums[i];
        }
        vector<vector<int>> dp(n, vector<int> (totalSum + 1, -1));

        for(int i=0; i<=totalSum; i++){
            bool dummy = f(n-1, i, nums, dp);
        }

        int mini = 1e9;
        for(int i=0; i<=totalSum; i++){
            if(dp[n-1][i] == true){
                int diff = abs(i - (totalSum - i));
                mini = min(mini, diff);
            }
        }
        return mini;
    }
};