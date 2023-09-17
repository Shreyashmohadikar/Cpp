class Solution {
public:
    bool f(int start, int end, bool turn, vector<int> &piles, vector<vector<int>> &dp){
        if(start > end){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        if(turn){//Alice picks
            int right = f(start, end-1, false, piles, dp) + piles[end];
            int left = f(start+1, end, false, piles, dp) + piles[start];
            return dp[start][end] = max(left, right);
        }
        else{//Bob picks
            int right = f(start, end-1, true, piles, dp) - piles[end];
            int left = f(start+1, end, true, piles, dp) - piles[start];
            return dp[start][end] = max(left, right);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int start = 0, end = n - 1;
        bool turn = true;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(start, end, turn, piles, dp);
    }
};