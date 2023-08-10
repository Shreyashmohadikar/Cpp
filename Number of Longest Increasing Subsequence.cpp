class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        int maxi = 0;
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(arr[i] > arr[prev] && 1+dp[prev] > dp[i]){
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if(arr[i] > arr[prev] && 1+dp[prev] == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi){
                count += cnt[i];
            }
        }
        return count;
    }
};