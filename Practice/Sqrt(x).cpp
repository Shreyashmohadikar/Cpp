class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1 ){
            return x;
        }
        int L = 0, R = x;
        while(L <= R){
            int mid = L + (R-L) / 2;
            if(mid == x / mid){
                return mid;
            }
            else if(mid > x / mid){
                R = mid - 1;
            }
            else{
                L = mid + 1;
            }
        }
        return R;
    }
};

