class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        bool flag = 0;
        for(int i=31; i>=0; i--){
            if(((n>>i) & 1) == 1){
                if(flag == 0){
                    ans += ((1 << (i+1))) - 1;
                    flag = 1;
                }
                else{
                    ans -= ((1 << (i+1))) - 1;
                    flag = 0;
                }
                cout<<ans<<endl;
            }
        }
        return ans;
    }
};