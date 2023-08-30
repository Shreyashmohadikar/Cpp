class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        int i=1;
        while(mp.count(i)){
            i++;
        }
        return i;
    }
};