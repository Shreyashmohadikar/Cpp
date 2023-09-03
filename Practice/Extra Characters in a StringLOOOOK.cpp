class Solution {
private:
    int f(int i, string &s, vector<string> &dict, vector<int> &dp){
        if(i == s.size()){
            return 0;
        }
        if(dp[i] == -1){
            dp[i] = 1 + f(i+1, s, dict, dp);

            for(auto &temp : dict){
                if(s.compare(i, temp.size(), temp) == 0){
                    dp[i] = min(dp[i], f(i + temp.size(), s, dict, dp));
                }
            }
        }
        return dp[i];
    }
public:
    int minExtraChar(string &s, vector<string>& dict) {
        vector<int> dp(s.size()+1, -1);
        return f(0, s, dict, dp);
    }
};


