class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for(auto curr : strs){
            string word = curr;
            sort(word.begin(), word.end());
            mp[word].push_back(curr);
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};
