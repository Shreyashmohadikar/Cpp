class Solution {
public:
    int f(vector<int> &arr, int target, vector<int> &dp){
        if(target < 0){
            return 0;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            ans += f(arr, target-arr[i], dp);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int> &arr, int target) {
        vector<int> dp(target+1, -1);
        dp[0] = 1;
        f(arr, target, dp);
        return dp[target];
    }
};

