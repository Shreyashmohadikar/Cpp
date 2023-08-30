class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int L = 0;
        int R = height.size() - 1;
        while(L < R){
            maxArea = max(maxArea, min(height[R], height[L]) * (R - L));
            if(height[L] < height[R]){
                L++;
            }
            else{
                R--;
            }
        }
        return maxArea;
    }
};