class Solution {
public:

    int f(int idx, vector<int> &nums, vector<int> &dp){
        if(idx < 0 ){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int pick = nums[idx] + f(idx-2, nums, dp);
        int notpick = 0 + f(idx-1, nums, dp);

        return dp[idx] = max(pick, notpick);
    }
    int rob(vector<int> &nums){
        int n = nums.size();
        // vector<int> temp1, temp2;
        // for(int i=0; i<n; i++){
        //     if(i != 0){
        //         temp1.push_back(nums[i]);
        //     }
        //     if(i != n-1){
        //         temp1.push_back(nums[i]);
        //     }
        // }
        // return max(f(n-1,temp1), f(n-1,temp2));
        vector<int> dp(n, -1);
        return f(n-1, nums, dp);
    }
};