class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans;
        for(auto it : nums){
            mp[it]++;
        }
        for(auto it : mp){
            if(it.second > 1){
                ans = it.first;
            }
        }
        return ans;
    }
};