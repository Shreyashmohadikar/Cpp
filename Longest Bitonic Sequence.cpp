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
    int notTake = f(i+1, prev, nums, dp);
    int take = 0;
    if(prev == -1 || nums[i] > nums[prev]){
        take = 1 + f(i+1, i, nums, dp);
    }
    return dp[i][prev+1] = max(take, notTake);
}

int g(int i, int prev, vector<int> &nums, vector<vector<int>> &dp1){
    if(i == nums.size()){
        return 0;
    }
    if(dp1[i][prev+1] != -1){
        return dp1[i][prev+1];
    }
    int notTake = g(i+1, prev, nums, dp1);
    int take = 0;
    if(prev == -1 || nums[i] < nums[prev]){
        take = 1 + g(i+1, i, nums, dp1);
    }
    return dp1[i][prev+1] = max(take, notTake);
}

int longestBitonicSubsequence(vector<int>& arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    vector<vector<int>> dp1(n, vector<int>(n+1, -1));
    int left = f(0, -1, arr, dp);
    int right = g(0, -1, arr, dp1);
    int maxBitonicLength = 0;
    for (int i = 0; i < n; ++i) {
        maxBitonicLength = max(maxBitonicLength, dp[i][i] + dp1[i][i] - 1);
    }
    return maxBitonicLength;
}

int main() {
    vector<int> arr = {1, 3, 5, 3, 2};
    int n = arr.size();
    int result = longestBitonicSubsequence(arr, n);
    cout << "Length of the longest bitonic subsequence: " << result << endl;
    return 0;
}
