class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            n &= (n-1);
            ans++;
        }
        return ans;
    }
};


///// Recursive

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0){
            return 0;
        }
        return (n & 1) + hammingWeight(n >> 1);
    }
};
