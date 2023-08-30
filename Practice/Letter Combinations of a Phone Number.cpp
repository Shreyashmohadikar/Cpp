class Solution {
public:
    void f(map<char, string> &mp, vector<string> &ans, 
            string &digits, int i, string currStr){
                if(digits.size() == currStr.size()){
                    ans.push_back(currStr);
                    return;
                }
                for(auto &c : mp[digits[i]]){
                    f(mp, ans, digits, i+1, currStr + c);
                }
            }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        if(digits.size()){
            f(mp, ans, digits, 0, "");
        }
        return ans;
    }
};