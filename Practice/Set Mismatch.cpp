class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;
        for(int& it : nums){//duplicate
            if(st.count(it)){
                ans.push_back(it);
            }
            st.insert(it);
        }
        for(int i=0; i<nums.size(); i++){//missing
            if(!st.count(i+1)){
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};