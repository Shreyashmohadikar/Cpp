class Solution {
public:
    int f(int n1, int n2, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(n1<0 || n2<0){
            return 0;
        }
        if(dp[n1][n2] != -1){
            return dp[n1][n2];
        }
        if(nums1[n1] == nums2[n2]){
            return dp[n1][n2] = 1 + f(n1-1, n2-1, nums1, nums2, dp);
        }
        else{
            return dp[n1][n2] = 0; //////// IMP       
        }

    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        int ans = 0;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                ans = max(ans, f(i, j, nums1, nums2, dp));
            }
        }
        return ans;
    }
};