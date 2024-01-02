class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
        }
        vector<vector<int>> ans;

        while(!mp.empty()){
            vector<int> temp;
            bool rowFlag = false;
            for(auto& it : mp){
                if(it.second > 0){
                    temp.push_back(it.first);
                    it.second -= 1;
                    rowFlag = true;
                }
            }    
            if(rowFlag){
                ans.push_back(temp);
            }
            else{
                break;
            }
        }
        return ans;
    }
};