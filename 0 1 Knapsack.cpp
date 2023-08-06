#include <bits/stdc++.h> 
int f(vector<int> &val, vector<int> &weight, int idx, int w, 
	vector<vector<int>> &dp){
	if(idx == 0){
		if(weight[0] <= w){
			return val[0];
		}
		else{
			return 0;
		}
	}
	if(dp[idx][w] != -1){
		return dp[idx][w];
	}
	int notTake = f(val, weight, idx - 1, w, dp);
	int take = INT_MIN;
	if(w >= weight[idx]){
		take =  val[idx] + f(val, weight, idx - 1, w-weight[idx], dp);
	}
	return dp[idx][w] = max(take, notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1)); 
	return f(value, weight, n-1, maxWeight, dp);
}

