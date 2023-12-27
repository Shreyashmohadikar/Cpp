class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i=0, j=1;
        int ans = 0;
        while(j<n){
            if(colors[i] == colors[j]){
                if(neededTime[i] < neededTime[j]){
                    ans += neededTime[i];
                    i = j;
                    j++;
                }
                else{
                    ans += neededTime[j];
                    j++;
                }
            }
            else{
                i = j;
                j++;
            }
        }
        return ans;
    }
};