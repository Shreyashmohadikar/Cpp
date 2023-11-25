class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        //left
        vector<int> left(n, 0);
        for(int i = 1; i < n; i++){
            left[i] = left[i-1] + (nums[i] - nums[i-1]) * i;
        }

        //right
        vector<int> right(n, 0);
        for(int i = n-2; i >= 0; i--){
            right[i] = right[i+1] + (nums[i+1] - nums[i]) * (n - i - 1);
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = left[i] + right[i];
        }
        return ans;
    }
};