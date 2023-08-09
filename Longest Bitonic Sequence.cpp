#include <iostream>
#include <vector>

using namespace std;

int f(int i, int prev, vector<int> &nums, vector<vector<int>> &dp, vector<vector<int>> &dp1){
    if(i == nums.size()){
        return 0;
    }
    if(dp[i][prev+1] != -1 && dp1[i][prev+1] != -1){
        return max(dp[i][prev+1], dp1[i][prev+1]);
    }
    
    int notTake = f(i+1, prev, nums, dp, dp1);
    int takeInc = 0;
    if(prev == -1 || nums[i] > nums[prev]){
        takeInc = 1 + f(i+1, i, nums, dp, dp1);
    }
    int takeDec = 0;
    if(prev == -1 || nums[i] < nums[prev]){
        takeDec = 1 + f(i+1, i, nums, dp, dp1);
    }
    
    dp[i][prev+1] = takeInc;
    dp1[i][prev+1] = takeDec;
    
    int maxBitonic = max(takeInc + takeDec - 1, notTake);
    return maxBitonic;
}

int lengthOfBitonicSubsequence(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    vector<vector<int>> dp1(n, vector<int>(n+1, -1));

    return f(0, -1, nums, dp, dp1);
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int bitonicLength = lengthOfBitonicSubsequence(arr);
    cout << bitonicLength << endl;
    return 0;
}
