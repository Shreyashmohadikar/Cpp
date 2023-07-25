
int f(int idx, int N, vector<int> &price, vector<vector<int>> &dp){
	if(idx == 0){
		return (N * price[0]);
	}
	if(dp[idx][N] != -1){
		return dp[idx][N];
	}
	int notpick = 0 + f(idx-1, N, price, dp);
	int pick = INT_MIN;
	int rodLength = idx + 1; 
	if(N >= rodLength){
		pick = price[idx] + f(idx, N - rodLength, price, dp);
	}
	return dp[idx][N] = max(pick, notpick);
}
    
int cutRod(vector<int> &price, int n) {
	vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	return f(n-1, n, price, dp); 
}