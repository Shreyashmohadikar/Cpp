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

////////////////////

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i=1;
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        while(st.count(i)){
            i++;
        }
        return i;
    }
};