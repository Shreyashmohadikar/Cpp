class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxTime = 0;
        for(auto pos : left){
            maxTime = max(maxTime, pos);
        }
        for(auto pos : right){
            maxTime = max(maxTime, n-pos);
        }
        return maxTime;
    }
};