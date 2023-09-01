class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

/////
//O(logn) using binary search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while(i <= j){
            int mid = i + (j-i)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >= nums[i]){
                if(target >= nums[i] && target < nums[mid]){
                    j = mid - 1;
                }
                else{
                    i = mid + 1;
                }
            }
            else if(nums[mid] <= nums[i]){
                if(target <= nums[j] && target > nums[mid]){
                    i = mid + 1;
                }
                else{
                    j = mid - 1;
                }
            }
        }
        return -1;
    }
};