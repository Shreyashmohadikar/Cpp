class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int Lmax = 0, Rmax = 0;

        for(int i=0; i<n; i++){
            if(height[i] > Lmax){
                Lmax = height[i];
            }
            left[i] = Lmax;
        }//Left max

        for(int i=n-1; i>=0; i--){
            if(height[i] > Rmax){
                Rmax = height[i];
            }
            right[i] = Rmax;
        }//Right max

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};
