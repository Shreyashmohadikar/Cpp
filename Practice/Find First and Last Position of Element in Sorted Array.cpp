class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int idx=-1, jdx=-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                idx = i;
                break;
            }
        }
        for(int j=nums.size() - 1; j>=0; j--){
            if(nums[j] == target){
                jdx = j;
                break;
            }
        }
        return {idx, jdx};
    }
};

/////////////////

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int L = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int R = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if(L <= R){
            return {L, R};
        }
        else{
            return {-1, -1};
        }
    }
};


///////////////
