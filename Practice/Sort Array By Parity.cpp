class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> arr;
        for(int it : nums){
            if(it % 2 == 0){
                arr.push_back(it);
            }
        }
        for(int it : nums){
            if(it % 2 != 0){
                arr.push_back(it);
            }
        }
        return arr;
    }
};

///////////////////////////

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0, j = nums.size()-1;
        while(i<j){
            while(i<j && nums[i] % 2 == 0){
                i++;
            }
            while(i<j && nums[j] % 2 == 1){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        return nums;
    }
};

