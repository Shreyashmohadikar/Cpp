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


