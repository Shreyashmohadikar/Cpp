class Solution {
public:
    int f(int i, vector<int> &arr, int k, int n, vector<int> &dp){
        if(i == arr.size()){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int len = 0, maxNum = INT_MIN, maxSum = 0;
        for(int j=i; j < min(n, i+k); j++){
            len++;
            maxNum = max(maxNum, arr[j]);
            int sum = len * maxNum + f(j+1, arr, k, n, dp);
            maxSum = max(maxSum, sum);
        }
        return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1, -1);
        return f(0, arr, k, n, dp);
    }
};