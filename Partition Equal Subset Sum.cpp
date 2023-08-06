class Solution {
public:
    bool f(int n, int target, vector<int> &arr, vector<vector<int>> &dp){
    if(target == 0){
        return true;
    }
    if(n == 0){
        return (arr[0] == target);
    }
    if(dp[n][target] != -1){
        return dp[n][target];
    }
    bool notTake = f(n-1, target, arr, dp);
    bool take = false;
    if(target >= arr[n]){
        take = f(n-1, target - arr[n], arr, dp);
    }
    return dp[n][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int totalsum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            totalsum += nums[i];
        }
        int target = totalsum / 2;
        vector<vector<int>> dp(n, vector<int>(target+1, -1)); 
        if(totalsum % 2 != 0){
            return false;
        }
        else{
            return f(n-1, target, nums, dp);
        }
    }
};
  