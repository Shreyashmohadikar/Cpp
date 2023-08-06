int Length(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
	if(i == nums.size()){
		return 0;
	}
	if(dp[i][prev+1] != -1){
		return dp[i][prev+1];
	}
	int notTake = 0 + Length(i+1, prev, nums, dp);
	int take = 0;
	if(prev == -1 || nums[i] > nums[prev]){
		take = 1 + Length(i+1, i, nums, dp);
	}
	return dp[i][prev+1] = max(take, notTake);
}

void printAns(int i, int prev, vector<int> &nums, vector<int> &ans, vector<vector<int>> &dp){
	if(i == nums.size()){
		return ;
	}
	if(Length(i, prev, nums, dp) == Length(i+1, prev, nums, dp)){
		printAns(i+1, prev, nums, ans, dp);
	}
	else{
		ans.push_back(nums[i]);
		printAns(i+1, i, nums, ans, dp);
	}
}
vector<int> printingLongestIncreasingSubsequence(vector<int>& nums, int n) {

	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	Length(0, -1, nums, dp);

	vector<int> ans;
	printAns(0, -1, nums, ans, dp);
	return ans;
}