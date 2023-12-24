class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int minOps = 0;
        for(int i=0; i<n; i++){
            if((s[i] - '0') != i % 2){
                minOps++;
            }
        }
        return min(minOps, n - minOps);
    }
};
