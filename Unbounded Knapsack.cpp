#include <bits/stdc++.h> 
int f(vector<int> &val, vector<int> &weight, int idx, int w, 
	vector<vector<int>> &dp){
	if(idx == 0){
		return int(w/weight[0]) * val[0];
	}
	if(dp[idx][w] != -1){
		return dp[idx][w];
	}
	int notTake = f(val, weight, idx - 1, w, dp); 
	int take = INT_MIN;
	if(w >= weight[idx]){
		take =  val[idx] + f(val, weight, idx, w-weight[idx], dp);
	}
	return dp[idx][w] = max(take, notTake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight) 
{
	vector<vector<int>> dp(n, vector<int>(w+1, -1)); 
	return f(profit, weight, n-1, w, dp);
}
