class Solution {
public:
    int f(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(n == 0){
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        if(dp[n][target] != -1){
            return dp[n][target];
        }
        int notpick = f(n-1, target, arr, dp);
        int pick = 0;
        if(target >= arr[n]){
            pick = f(n-1, target - arr[n], arr, dp);
        }
        return dp[n][target] = pick + notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum+=nums[i];
        }
        if((totalSum - target) % 2 == 1 || (totalSum - target)<0){
            return 0;
        }
        int s2 = (totalSum - target)/2;
        vector<vector<int>> dp(n, vector<int>(s2+1, -1));
        return f(n-1, s2, nums, dp);
    }
};