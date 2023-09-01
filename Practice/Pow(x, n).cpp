class Solution {
public:
    double myPow(double x, int n) {
        double ans;
        if (n==0){
            return 1.0;
        }
        if(n<0){
            n = abs(n);
            x=1/x;
        }
        if(n%2 == 0){
            ans = myPow(x*x, n/2);
        }
        else{
            ans = x * myPow(x, n-1);
        }
        return ans;
    }
};