class Solution {
private:
    long long solve(vector<int> &arr, int i, unordered_map<int, int> &mp, vector<int> &dp){
        if(i < 0){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        long long count = 1;
        for(int j=0; j<i; j++){
            if(arr[i] % arr[j] == 0 && mp.count(arr[i] / arr[j])){
                long long left = solve(arr, j, mp, dp);
                long long right = solve(arr, mp[arr[i] / arr[j]], mp, dp);
                count = (count + (left*right) % MOD) % MOD;
            }
        }
        return dp[i] = count;
    }
public:
    const int MOD = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        int n = arr.size();
        for(int i=0; i<n; i++){
            mp[arr[i]] = i;
        }
        int count = 0;
        for(int i=n-1; i>=0; i--){
            vector<int> dp(n+1, -1);
            count = (count + (int)solve(arr, i, mp, dp)) % MOD;
        }
        return count;
    }
};