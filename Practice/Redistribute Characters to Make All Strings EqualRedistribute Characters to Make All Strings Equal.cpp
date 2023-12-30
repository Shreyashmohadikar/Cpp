class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> mp;
        for(string& word : words){
            for(char& c : word){
                mp[c]++;
            }
        }
        for(auto& it : mp){
            if(it.second % n != 0){
                return false;
            }
        }
        return true;
    }
};