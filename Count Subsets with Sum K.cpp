const int MOD = 1000000007;
int f(int n, int target, vector<int>& nums, vector<vector<int>> &dp){

	if(target == 0){
		return 1;
	}
	if(n == 0){
		return (nums[n] == target);
	}
	if (n < 0) {
        return 0;
    }
	if(dp[n][target] != -1){
		return dp[n][target];
	}
	int pick = 0;
	if(target >= nums[n]){
		pick = f(n-1, target-nums[n], nums, dp);
	}
	int notpick = f(n-1, target, nums, dp);
	return dp[n][target] = (pick + notpick)  % MOD;
}
int findWays(vector<int>& nums, int target) {
	int n = nums.size();
	vector<vector<int>> dp(n, vector<int>(target+1, -1));
	return f(n-1, target, nums, dp);
}