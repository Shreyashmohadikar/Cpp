class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        unordered_set<int> uniq;
        for(auto& it : arr){
            mp[it]++;
        }
        for(auto& it : mp){
            if(uniq.count(it.second)){
                return false;
            }
            uniq.insert(it.second);
        }
        return true;
    }
};