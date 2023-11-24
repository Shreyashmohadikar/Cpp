class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());
        int ans = 0;
        int n = (2 * piles.size()) / 3;
        for(int i=1; i<n; i+=2){
            ans += piles[i];
        }
        return ans;
    }
};