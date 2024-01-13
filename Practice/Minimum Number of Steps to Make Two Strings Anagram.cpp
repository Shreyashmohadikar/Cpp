class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;
        for(char& c : s){
            mp1[c]++;
        }
        for(char& c : t){
            mp2[c]++;
        }
        int ans = 0;
        for(char it = 'a'; it <= 'z'; it++){
            ans += abs(mp1[it] - mp2[it]);
        }
        return ans / 2;
    }
};