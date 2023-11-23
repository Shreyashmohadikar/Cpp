class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++){
            int left = l[i];
            int right = r[i];

            if((right - left) < 1){
                ans.push_back(false);
            }
            else{
                vector<int> temp(nums.begin() + left, nums.begin() + right + 1);
                sort(temp.begin(), temp.end());

                bool flag = true;
                for(int j = 1; j < temp.size() - 1; j++){
                    if((temp[j] - temp[j - 1]) != (temp[j + 1] - temp[j])){
                        flag = false;
                        break;
                    }
                }
                ans.push_back(flag);
            }
        }
        return ans;
    }
};