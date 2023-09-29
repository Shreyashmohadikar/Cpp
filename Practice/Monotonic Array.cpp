class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int flag = 0;
        //0 - unknown
        //1 - increasing
        //-1 - decreasing

        for(int i=1; i<nums.size(); i++){
            if(nums[i-1] < nums[i]){
                if(flag == 0){
                    flag = -1;
                }
                else if(flag == 1){
                    return false;
                }
            }

            else if(nums[i-1] > nums[i]){
                if(flag == 0){
                    flag = 1;
                }
                else if(flag == -1){
                    return false;
                }
            }
        }
        return true;
    }
};

