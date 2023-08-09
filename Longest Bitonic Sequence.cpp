#include <iostream>
#include <vector>

using namespace std;

int f(int i, int prev, vector<int> &nums, vector<vector<int>> &dp){
    if(i == nums.size()){
        return 0;
    }
    if(dp[i][prev+1] != -1){
        return dp[i][prev+1];
    }
    int notTake = 0 + f(i+1, prev, nums, dp);
    int take = 0;
    if(prev == -1 || nums[i] < nums[prev]){
        take = 1 + f(i+1, i, nums, dp);
    }
    return dp[i][prev+1] = max(take, notTake);
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, -1, nums, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int lisLength = lengthOfLIS(arr);
    cout << lisLength << endl;
    return 0;
}
