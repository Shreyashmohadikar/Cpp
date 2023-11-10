//Brute Force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};


//Optimized
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i=0; i<n; i++){
            int complement = target - nums[i];
            if(mp.count(complement)){
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};