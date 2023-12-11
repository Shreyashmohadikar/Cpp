class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(const auto& it : arr){
            mp[it]++;
        }
        for(const auto& it : mp){
            if(it.second > n/4){
                return it.first;
            }
        }
        return 0;
    }
};