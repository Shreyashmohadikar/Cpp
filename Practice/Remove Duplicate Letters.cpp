class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq(26);
        unordered_map<char, int> vis(26);
        string ans = "";
        for(auto ch : s){
            freq[ch]++;
        }
        for(auto ch : s){
            freq[ch]--;
            if(vis[ch]){
                continue;
            }
            while(!ans.empty() && freq[ans.back()] && ans.back()>ch){
                vis[ans.back()] = 0;
                ans.pop_back();
            }
            ans.push_back(ch);
            vis[ch] = 1;
        }
        return ans;
    }
};

