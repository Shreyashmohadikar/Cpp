class Solution {
public:
    void swap(vector<int> &nums, int i, int idx){
        int temp = nums[i];
        nums[i] = nums[idx];
        nums[idx] = temp;
    }
    void f(int idx, vector<int> &nums,
            vector<vector<int>> &ans){

        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=idx; i<nums.size(); i++){
            swap(nums, i, idx);
            f(idx+1, nums, ans);
            swap(nums, i, idx); //Backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()){
            f(0, nums, ans);
        }
        return ans;
    }
};